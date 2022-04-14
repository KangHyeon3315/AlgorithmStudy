#include <iostream>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    int horizontal = 0, vertical = 0;
    char space[n][n];
    int vertical_space[n]; 
    for(int i = 0; i < n; i++) {
        vertical_space[i] = 0;
        for(int j = 0; j < n; j++) {
            cin >> space[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        int blank_count = 0;
        for(int j = 0; j < n; j++) {
            if (space[i][j] == '.') {
                blank_count++;
                vertical_space[j]++;
            } else {
                if(blank_count > 1)
                    horizontal++;
                blank_count = 0;

                if(vertical_space[j] > 1) {
                    vertical++;
                }
                vertical_space[j] = 0;
            }
        }
        if(blank_count > 1)
            horizontal++;
        blank_count = 0;
    }

    for(int j = 0 ; j < n; j++) {
        if(vertical_space[j] > 1) {
            vertical++;
        }
        vertical_space[j] = 0;
    }

    cout << horizontal << " " << vertical << endl;
}