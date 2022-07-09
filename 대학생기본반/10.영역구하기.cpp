#include <iostream>
#include <algorithm>
using namespace std;

int m, n, k;
int area[100][100];
bool checked[100][100];
int spaceArea[100];
int spaceIdx = 0;

int verticalDir[] = {1, -1, 0, 0};
int horizontalDir[] = {0, 0, 1, -1};

void dfs(int x, int y)
{
    checked[x][y] = true;

    for (int dirIdx = 0; dirIdx < 4; dirIdx++)
    {
        int movedX = x + horizontalDir[dirIdx];
        int movedY = y + verticalDir[dirIdx];

        if (movedX < 0 || movedX >= n || movedY < 0 || movedY >= m)
            continue;

        if (area[movedX][movedY] == 0 && !checked[movedX][movedY])
        {
            spaceArea[spaceIdx]++;
            dfs(movedX, movedY);
        }
    }
}

int main(void)
{
    cin >> m >> n >> k;

    for (int i = 0; i < k; i++)
    {
        int x1, x2, y1, y2;

        cin >> x1 >> y1 >> x2 >> y2;

        for (int x = x1; x < x2; x++)
        {
            for (int y = y1; y < y2; y++)
            {
                area[x][y] = 1;
            }
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (area[i][j] == 0 && !checked[i][j])
            {
                spaceArea[spaceIdx] = 1;
                dfs(i, j);
                count++;
                spaceIdx++;
            }
        }
    }

    cout << count << endl;
    sort(spaceArea, spaceArea + count);
    for(int i = 0 ; i < count; i++) {
        cout << spaceArea[i] << " ";
    }
    cout << endl;
}