#include <iostream>
#include <cstring>

using namespace std;

int area[51][51];
bool checkedArea[51][51];

int verticalDir[] = {1, -1, 0, 0};
int horizontalDir[] = {0, 0, 1, -1};

int m, n, k;

void dfs(int x, int y)
{
    checkedArea[x][y] = true;

    for (int dirIdx = 0; dirIdx < 4; dirIdx++)
    {
        int movedX = x + horizontalDir[dirIdx];
        int movedY = y + verticalDir[dirIdx];

        if (movedX < 0 || movedX >= m || movedY < 0 || movedY >= n)
            continue;

        if (area[movedX][movedY] == 1 && !checkedArea[movedX][movedY])
        {
            dfs(movedX, movedY);
        }
    }
}

int main(void)
{
    int t;
    cin >> t;

    while(t--) {
        cin >> m >> n >> k;
        int count = 0;
        for(int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            area[x][y] = 1;
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(area[i][j] == 1 && !checkedArea[i][j]) {
                    count++;
                    dfs(i, j);
                }
            }
        } 

        cout << count << endl;
        memset(checkedArea, false, sizeof(checkedArea));
        memset(area, 0, sizeof(area));
    }
}

