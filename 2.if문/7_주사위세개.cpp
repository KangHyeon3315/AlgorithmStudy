#include <iostream>
using namespace std;

int main()
{
    int a, b, c;

    cin >> a >> b >> c;

    if (a == b && b == c)
    {
        cout << 10000 + a * 1000 << endl;
    }
    else if (a == b || b == c || a == c)
    {
        if(a == b || a == c) {
            cout << 1000 + a * 100 << endl;
        } else {
            cout << 1000 + b * 100 << endl;
        }
    } else {
        int max = a > b ? a : b;
        max = max > c ? max : c;

        cout << max * 100 << endl;
    }

    return 0;
}