#include <bits/stdc++.h>
using namespace std;

int n, m, r, c, d;

int arr[55][55];
int ch[55][55];

int dx[4] = {0, 1, 0, -1}; // 북 (0,1,0,-1)  서 (1,0,-1,0) 남 (0,-1,0,1) 동 (-1,0,1,0)
int dy[4] = {-1, 0, 1, 0}; // 북 (-1,0,1,0)  서 (0,1,0,-1) 남 (1,0,-1,0) 동 (0,-1,0,1)

queue<tuple<int, int, int, int>> q;

bool func(int x, int y)
{
    if (ch[x][y] > 0 || arr[x][y] == 1)
        return true;

    return false;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> r >> c >> d;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    if (d == 1)
    {
        d = 3;
    }
    else if (d == 3)
    {
        d = 1;
    }

    ch[r][c] = 1;
    q.push({r, c, d, 1});

    int ans = 0;

    while (!q.empty())
    {
        tuple<int, int, int, int> cur = q.front();
        q.pop();

        int x = get<0>(cur);
        int y = get<1>(cur);
        int dir = get<2>(cur);
        int cnt = get<3>(cur);

        // cout << x << " " << y << " " << dir << "\n";

        bool isFind = 0;

        for (int i = 0; i < 4; i++)
        {
            int num = (i + dir) % 4;
            int nx = x + dx[num];
            int ny = y + dy[num];

            if (func(nx, ny))
            {
                continue;
            }
            ch[nx][ny] = cnt + 1;
            q.push({nx, ny, (dir + i + 1) % 4, cnt + 1});
            isFind = 1;
            break;
        }

        if (isFind == 0)
        {
            int num = (dir + 1) % 4;
            int nx = x + dx[num];
            int ny = y + dy[num];

            if (arr[nx][ny] == 1)
                continue;

            q.push({nx, ny, dir, cnt});
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (ch[i][j] >= 1)
                ans++;
            // cout << ch[i][j] << " ";
        }
        // cout << "\n";
    }
    cout << ans;
}
