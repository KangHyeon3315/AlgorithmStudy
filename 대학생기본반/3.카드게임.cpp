#include <iostream>
using namespace std;

int main (void) {
    int color[] = {0, 0, 0, 0};
    int num[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    char ch;
    int n;
    int largest_num = 0;

    for(int i = 0 ; i < 5; i++) {
        cin >> ch >> n;

        if(ch == 'R')
            color[0]++;
        else if(ch == 'B')
            color[1]++;
        else if(ch == 'Y')
            color[2]++;
        else
            color[3]++;
        
        num[n - 1]++;
        largest_num = n > largest_num ? n : largest_num;
    }

    int score = 0;
    int max = 0;
    bool continuous = false;
    int continuous_count = 0;
    int equal[2][5] = {{-1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1}};

    for(int i = 0 ; i < 9; i++) {
        if(continuous_count == 0 && num[i] != 0) {
            continuous = true;
            continuous_count++;
        } else if(continuous && num[i] != 0) {
            continuous_count++;
        } else if(continuous && num[i] == 0) {
            continuous = false;
        }

        if(num[i] > 0) {
            max = i + 1;
            equal[equal[0][num[i] - 1] == -1 ? 0 : 1][num[i] - 1] = i + 1;
        }
    }

    if((color[0] == 5 || color[1] == 5 || color[2] == 5 || color[3] == 5) && continuous_count == 5) {
        score = max + 900;
    } else if(equal[0][4 - 1] != -1) {
        score = equal[0][4 - 1] + 800;
    } else if(equal[0][3 - 1] != -1 && equal[0][2 - 1] != -1) {
        score = equal[0][3 - 1] * 10 + equal[0][2 -1] + 700;
    } else if(color[0] == 5 || color[1] == 5 || color[2] == 5 || color[3] == 5) {
        score = max + 600;
    } else if(continuous_count == 5) {
        score = max + 500;
    } else if(equal[0][3 - 1] != -1) {
        score = equal[0][3 - 1] + 400;
    } else if (equal[0][2 - 1] != -1 && equal[1][2 - 1] != -1) {
        int max = equal[0][2 - 1] > equal[1][2 - 1] ? equal[0][2 - 1] : equal[1][2 - 1];
        int min = equal[0][2 - 1] < equal[1][2 - 1] ? equal[0][2 - 1] : equal[1][2 - 1];

        score = max * 10 + min + 300;
    } else if(equal[0][2 - 1] != -1) {
        score = equal[0][2 - 1] + 200;
    } else {
        score = max + 100;
    }

    cout << score << endl;

    return 0;
}