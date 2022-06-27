#include <bits/stdc++.h>
using namespace std;

int arr[22][22];
bool ch[22][22];

int dx[8] = {1, 0, 1, 1, -1, 0, -1, -1};
int dy[8] = {0, 1, 1, -1, 0, -1, -1, 1};

bool func(int x, int y)
{

    int num = arr[x][y];

    int dir = 0;

    while (dir != 4)
    {
        int cnt = 1;

        int nx = x;
        int ny = y;

        int nxx = x;
        int nyy = y;

        for (int i = 0; i < 20; i++)
        {
            nx += dx[dir];
            ny += dy[dir];

            if (nx < 1 || ny < 1 || nx >= 20 || ny >= 20 || cnt > 5 || arr[nx][ny] != num)
            {
                nx += dx[dir + 4];
                ny += dy[dir + 4];
                break;
            }
            if (num == arr[nx][ny])
            {
                cnt++;
            }
        }

        for (int i = 0; i < 20; i++)
        {
            nxx += dx[dir + 4];
            nyy += dy[dir + 4];

            if (nxx < 1 || nyy < 1 || nxx >= 20 || nyy >= 20 || cnt > 5 || arr[nxx][nyy] != num)
            {
                nxx += dx[dir];
                nyy += dy[dir];
                break;
            }
            if (num == arr[nxx][nyy])
            {
                cnt++;
            }
        }
        // cout << dir << " " << cnt << "\n";

        if (cnt == 5)
        {
            cout << num << "\n";
            if (y < ny)
            {
                cout << x << " " << y << "\n";
            }
            else if (y > ny)
            {
                cout << nx << " " << ny << " "
                     << "\n";
            }
            else
            {

                if (x < nx)
                {

                    cout << x << " " << y << "\n";
                }
                else
                {
                    cout << nx << " " << ny << " "
                         << "\n";
                }
            }
            return true;
        }

        dir++;
    }
    return false;
}

queue<tuple<int, int, int, int>> q;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1; i <= 19; i++)
    {
        for (int j = 1; j <= 19; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= 19; i++)
    {
        for (int j = 1; j <= 19; j++)
        {

            if (arr[i][j] != 0)
            {
                // func(i, j);
                if (func(i, j) == 1)
                {
                    return 0;
                };
            }
        }
    }

    // func(19, 19);

    cout << 0;
    return 0;
}
