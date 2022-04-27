#include <iostream>
using namespace std;

void swap(string* ch, int idx1, int idx2) {
    string tmp;
    tmp = ch[idx1];
    ch[idx1] = ch[idx2];
    ch[idx2] = tmp;
}

int main(void) {
    int n, cursor = 0;
    bool kbs1 = false;
    bool kbs2 = false;
    cin >> n;
    string ch[n];
    
    for(int i = 0 ; i < n; i++) {
        cin >> ch[i];
    }

    while(!kbs1 || !kbs2) {
        if(!kbs1) {
            if(ch[cursor] != "KBS1") {
                cursor++;
                cout << 1;
            } else if(cursor != 0) {
                swap(ch, cursor - 1, cursor);
                cursor -= 1;
                cout << 4;
            } else {
                kbs1 = true;
            }
        } else if(!kbs2) {
            if(ch[cursor] != "KBS2") {
                cursor++;
                cout << 1;
            } else if(cursor != 1) {
                swap(ch, cursor - 1, cursor);
                cursor -= 1;
                cout << 4;
            } else {
                kbs2 = true;
            }
        }
    }
}