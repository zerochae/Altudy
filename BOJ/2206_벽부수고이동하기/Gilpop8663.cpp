#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[1005][1005];
bool ch[1005][1005][2] = {0};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<tuple<int, int, int, bool>> q;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int ans = 1e9;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;

        for (int j = 0; j < m; j++)
        {
            arr[i][j] = str[j] - '0';
        }
    }

    ch[0][0][1] = 1;
    ch[0][0][0] = 1;
    q.push({0, 0, 1, 1});

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        int x = get<0>(cur);
        int y = get<1>(cur);
        int cnt = get<2>(cur);
        bool isBreak = get<3>(cur);

        if (x == n - 1 && y == m - 1)
        {
            ans = min(ans, cnt);
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m || ch[nx][ny][isBreak] == 1)
                continue;
            if (arr[nx][ny] == 1 && isBreak == 0)
            {
                continue;
            }
            if (arr[nx][ny] == 1 && isBreak == 1)
            {
                ch[nx][ny][0] = 1;
                q.push({nx, ny, cnt + 1, 0});
            }
            if (arr[nx][ny] == 0)
            {
                ch[nx][ny][isBreak] = 1;
                q.push({nx, ny, cnt + 1, isBreak});
            }
        }
    }

    if (ans == 1e9)
    {
        cout << -1;
    }
    else
    {
        cout << ans;
    }
}
