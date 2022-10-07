#include <bits/stdc++.h>
using namespace std;

int n, m, t;

int arr[105][105];
bool ch[105][105];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int ans = 1e9;

queue<tuple<int, int, int, bool>> q;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> t;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    ch[0][0] = 1;

    if (arr[0][0] == 0)
    {

        q.push({0, 0, 0, 0});
    }
    else if (arr[0][0] == 2)
    {
        q.push({0, 0, 0, 1});
    }

    pair<int, int> gram;

    int gramWayCnt = 0;

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        int x = get<0>(cur);
        int y = get<1>(cur);
        int cnt = get<2>(cur);
        bool isFind = get<3>(cur);

        if (x == n - 1 && y == m - 1)
        {
            ans = min(ans, cnt);
            continue;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (ch[nx][ny] == 1)
                continue;

            if (arr[nx][ny] == 0)
            {
                ch[nx][ny] = 1;
                q.push({nx, ny, cnt + 1, isFind});
            }
            if (arr[nx][ny] == 2)
            {
                ch[nx][ny] = 1;
                q.push({nx, ny, cnt + 1, 1});
                gram.first = nx;
                gram.second = ny;
                gramWayCnt = cnt + 1;
            }
        }
    }

    fill(&ch[0][0], &ch[104][105], 0);

    if (arr[gram.first][gram.second] != 2)
    {
        cout << "Fail";
        return 0;
    }

    ch[gram.first][gram.second] = 1;
    q.push({gram.first, gram.second, gramWayCnt, 1});

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        int x = get<0>(cur);
        int y = get<1>(cur);
        int cnt = get<2>(cur);
        bool isFind = get<3>(cur);

        if (x == n - 1 && y == m - 1)
        {
            ans = min(ans, cnt);
            continue;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (ch[nx][ny] == 1)
                continue;

            ch[nx][ny] = 1;
            q.push({nx, ny, cnt + 1, 1});
        }
    }

    if (t >= ans)
    {
        cout << ans;
    }
    else
    {
        cout << "Fail";
    }
}
