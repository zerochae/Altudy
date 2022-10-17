#include <bits/stdc++.h>
using namespace std;

int n;

int arr[105][105];
int ch[105][105];

int dist[105][105];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<pair<int, int>> q;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    int cnt = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (ch[i][j] > 0 || arr[i][j] == 0)
                continue;
            if (arr[i][j] == 1)
            {
                ch[i][j] = cnt;
                q.push({i, j});

                while (!q.empty())
                {
                    auto cur = q.front();
                    q.pop();

                    int x = cur.first;
                    int y = cur.second;

                    for (int k = 0; k < 4; k++)
                    {
                        int nx = x + dx[k];
                        int ny = y + dy[k];

                        if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                            continue;

                        if (ch[nx][ny] > 0 || arr[nx][ny] == 0)
                            continue;
                        ch[nx][ny] = cnt;
                        q.push({nx, ny});
                    }
                }

                cnt++;
            }
        }
    }

    fill(&dist[0][0], &dist[104][105], -1);

    int ans = 999999;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (ch[i][j] != 0)
            {
                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        int x = cur.first;
        int y = cur.second;

        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                continue;
            if (ch[x][y] == ch[nx][ny])
                continue;

            if (ch[nx][ny] != 0 && ch[nx][ny] != ch[x][y]) //인접한 섬이 다른 섬일 경우
            {
                ans = min(ans, dist[x][y] + dist[nx][ny]); // cur 과 (nx,ny) 각각이 육지로 부터 떨어진 거리를 더함
            }
            else //바다인 경우
            {
                ch[nx][ny] = ch[x][y];
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    cout << ans;
}
