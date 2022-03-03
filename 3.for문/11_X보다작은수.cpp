#include <iostream>
using namespace std;

int main(void) {
    int n, max, val;
    cin >> n >> max;
    
    for(int i = 1; i <= n; i++){
        cin >> val;
        if(val < max) {
            cout << val << " ";
        }
    }
    cout << endl;

    return 0;
}