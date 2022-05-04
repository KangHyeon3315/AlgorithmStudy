#include <iostream>
using namespace std;

int main(void)
{
    int n, m;
    cin >> n >> m;

    int connected_count = 0;
    int connected_component[n];
    for (int i = 0; i < n; i++)
        connected_component[i] = 0;

    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        
        if (connected_component[a - 1] != 0 && connected_component[b - 1] != 0)
        {
            if (connected_component[a - 1] != connected_component[b - 1])
            {
                connected_count--;
                int max = connected_component[a - 1] > connected_component[b - 1] ? connected_component[a - 1] : connected_component[b - 1];
                int min = connected_component[a - 1] < connected_component[b - 1] ? connected_component[a - 1] : connected_component[b - 1];

                for (int i = 0; i < n; i++)
                {
                    if (connected_component[i] == max)
                    {
                        connected_component[i] = min;
                    }
                    else if (connected_component[i] > max)
                    {
                        connected_component[i]--;
                    }
                }
            }
        }
        else if (connected_component[a - 1] != 0)
        {
            connected_component[b - 1] = connected_component[a - 1];
        }
        else if (connected_component[b - 1] != 0)
        {
            connected_component[a - 1] = connected_component[b - 1];
        }
        else
        {
            connected_count++;
            connected_component[a - 1] = connected_count;
            connected_component[b - 1] = connected_count;
        }
    }

    for(int i = 0; i < n; i++) {
        if(connected_component[i] == 0) {
            connected_count++;
            connected_component[i] = connected_count;
        }
    }

    cout << connected_count << endl;
}