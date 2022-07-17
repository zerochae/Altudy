#include <bits/stdc++.h>
using namespace std;

int n, m, r;

int arr[305][305];

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

bool ch[305][305] = {0};

void func()
{
    int tmp[305][305];

    for (int i = 0; i < n / 2; i++)
    {

        int sy = i;
        int sx = i;

        int dir = 0;

        while (1)
        {

            int num = arr[sy][sx];

            int ny = sy + dy[dir];
            int nx = sx + dx[dir];
            if (nx < 0 + i || ny < 0 + i || nx >= m - i || ny >= n - i)
            {
                dir++;

                if (dir == 4)
                {
                    break;
                }
                continue;
            }

            sy = ny;
            sx = nx;

            tmp[ny][nx] = num;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = tmp[i][j];

            // cout << arr[i][j] << " ";
        }
        // cout << "\n";
    }

    return;
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> r;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < r; i++)
    {

        func();
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}
