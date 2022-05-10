#include <iostream>
using namespace std;

int main(void) {
    int node, edge;

    cin >> node >> edge;

    int n1, n2;
    int connected_count = 0;
    int connect[node];

    for(int i = 0 ; i < node; i++) {
        connect[i] = 0;
    }

    for(int i = 0 ; i < edge; i++) {
        cin >> n1 >> n2;

        if(connect[n1 - 1] != 0 && connect[n2 - 1] != 0) {
            if(connect[n1 - 1] != connect[n2 - 1]) {
                connected_count--;
                int big = connect[n1 - 1] > connect[n2 - 1] ? connect[n1 - 1] : connect[n2 - 1];
                int small = connect[n1 - 1] < connect[n2 - 1] ? connect[n1 - 1] : connect[n2 - 1];

                for(int j = 0; j < node; j++) {
                    if(connect[j] == big) {
                        connect[j] = small;
                    } else if(connect[j] > big) {
                        connect[j]--;
                    }
                }
            }
        } else if(connect[n1 - 1] != 0 ) {
            connect[n2 - 1] = connect[n1 - 1];

        } else if(connect[n2 - 1] != 0) {
            connect[n1 - 1] = connect[n2 - 1];
        } else {
            connected_count++;
            connect[n1 - 1] = connected_count;
            connect[n2 - 1] = connected_count;
        }
    }

    if(connect[0] == 0)  {
        cout << 0 << endl;
    } else {
        connected_count = 0;
        for(int i = 1 ; i < node; i++) {
            if(connect[i] == connect[0])       
                connected_count++;
        }
        cout << connected_count << endl;
    }
    
}