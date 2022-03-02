#include <iostream>
using namespace std;

int main()
{
    int hour, minute, need;

    cin >> hour >> minute >> need;

    minute += need;

    hour += minute / 60;
    minute = minute % 60;
    hour %= 24;
    
    cout << hour << ' ' << minute << endl;
    return 0;
}