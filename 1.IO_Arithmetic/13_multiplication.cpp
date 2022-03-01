#include <iostream>
using namespace std;

int main(void)
{
    int a, b, c;

    cin >> a >> b;
    c = b;

    while (c > 0)
    {
        cout << a * (c % 10) << endl;
        c /= 10;
    }
    cout << a * b << endl;
    return 0;
}