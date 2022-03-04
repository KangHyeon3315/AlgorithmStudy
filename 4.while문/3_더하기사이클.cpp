#include <iostream>
using namespace std;

int main(void)
{
    int n, x, i;
    cin >> n;
    x = n;
    i = 0;
    while (true)
    {
        i++;
        x = x % 10 * 10 + (x / 10 + x % 10) % 10;

        if (x == n)
        {
            break;
        }
    }
    cout << i << endl;

    return 0;
}