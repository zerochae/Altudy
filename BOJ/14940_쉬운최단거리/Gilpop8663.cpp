#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[1005][1005];

int ans[1005][1005];

bool ch[1005][1005];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<tuple<int, int, int>> q;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    bool isFind = 0;
    for (int i = 0; i < n; i++)
    {
        if (isFind == 1)
            break;
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 2)
            {
                isFind = 1;
                ch[i][j] = 1;
                q.push({i, j, 0});
                break;
            }
        }
    }

    while (!q.empty())
    {
        tuple<int, int, int> cur = q.front();
        q.pop();

        int x = get<0>(cur);
        int y = get<1>(cur);
        int dis = get<2>(cur);

        ans[x][y] = dis;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || ch[nx][ny] == 1)
                continue;
            if (arr[nx][ny] == 1)
            {
                ch[nx][ny] = 1;
                q.push({nx, ny, dis + 1});
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (ans[i][j] == 0 && arr[i][j] == 1)
            {
                ans[i][j] = -1;
            }
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}
