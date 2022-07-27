#include <bits/stdc++.h>
using namespace std;

int arr[105][105][105];
int ans[105][105][105];
bool ch[105][105][105] = {0};

int n, m, h;

int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

queue<tuple<int, int, int, int>> q;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> h;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                cin >> arr[i][j][k];
                if (arr[i][j][k] == 1)
                {
                    ch[i][j][k] = 1;
                    q.push({i, j, k, 0});
                }
            }
        }
    }

    while (!q.empty())
    {
        tuple<int, int, int, int> cur = q.front();
        q.pop();

        int z = get<0>(cur);
        int y = get<1>(cur);
        int x = get<2>(cur);
        int cnt = get<3>(cur);

        ans[z][y][x] = cnt;

        for (int i = 0; i < 6; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];

            if (nx < 0 || ny < 0 || nz < 0 || nx >= m || ny >= n || nz >= h)
                continue;
            if (ch[nz][ny][nx] == 1)
                continue;
            if (arr[nz][ny][nx] == 0)
            {
                ch[nz][ny][nx] = 1;
                q.push({nz, ny, nx, cnt + 1});
            }
        }
    }

    bool isFind = 0;
    for (int i = 0; i < h; i++)
    {
        if (isFind == 1)
            continue;
        for (int j = 0; j < n; j++)
        {
            if (isFind == 1)
                continue;
            for (int k = 0; k < m; k++)
            {
                if (ans[i][j][k] == 0 && arr[i][j][k] == 0)
                {
                    isFind = 1;
                    break;
                }
            }
        }
    }

    if (isFind == 1)
    {
        cout << -1;
    }
    else
    {
        int maxNum = 0;
        for (int i = 0; i < h; i++)
        {

            for (int j = 0; j < n; j++)
            {

                for (int k = 0; k < m; k++)
                {
                    maxNum = max(maxNum, ans[i][j][k]);
                }
            }
        }
        cout << maxNum;
    }
}
