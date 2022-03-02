#include <iostream>
using namespace std;

int main()
{
    int hour, minute;

    cin >> hour >> minute;

    minute -= 45;

    if(minute < 0) {
        hour--;
        minute = 60 + minute;
    }
    if(hour < 0) {
        hour = 24 + hour;
    }
    cout << hour << ' ' << minute << endl;
    return 0;
}