#include <iostream>
using namespace std;

int main(void) {
    int n, k;

    cin >> n >> k;

    
    int medal[n][3];

    int c;
    for(int i = 0 ; i < n; i++) {
        cin >> c;
        for(int j = 0; j < 3; j++) {
            cin >> medal[c - 1][j];
        }
    }

    int rank = 1;
    for(int i = 0 ; i < n; i++) {
        if(i == k - 1)
            continue;
        
        if(medal[i][0] > medal[k - 1][0]) {
            rank++;
        } else if(medal[i][0] == medal[k - 1][0]){
            if(medal[i][1] > medal[k - 1][1]) {
                rank++;
            } else if(medal[i][1] == medal[k -1][1]) {
                if(medal[i][2] > medal[k - 1][2]) {
                    rank++;
                }
            }
        }
    }

    cout << rank << endl;
}