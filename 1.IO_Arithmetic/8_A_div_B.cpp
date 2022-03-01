#include <iostream>
using namespace std;

int main(void)
{
    int num1, num2, rest, result;

    cin >> num1 >> num2;

    cout << num1 / num2 << ".";

    rest = num1 % num2;
    for (int i = 0; i < 30; i++)
    {
        if (rest == 0)
            break;

        rest *= 10;

        result = rest / num2;
        rest %= num2;

        cout << result;
    }
    cout << endl;
    return 0;
}