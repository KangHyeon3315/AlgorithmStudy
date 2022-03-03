#include <iostream>
using namespace std;

int main(void) {
    int n, a, b;
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        for(int j = n; j > i; j--){
            cout << ' ';
        }
        for(int j = 1; j <= i; j++){
            cout << '*';
        }    
        cout << endl;
    }

    return 0;
}