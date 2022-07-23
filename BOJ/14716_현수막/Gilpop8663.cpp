#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[255][255];
bool ch[255][255];

int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};

queue<pair<int, int>> q;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (ch[i][j] == 1)
                continue;
            if (arr[i][j] == 1)
            {
                q.push({i, j});
                ch[i][j] = 1;
                ans++;
            }

            while (!q.empty())
            {
                pair<int, int> cur = q.front();
                q.pop();

                int x = cur.first;
                int y = cur.second;

                for (int k = 0; k < 8; k++)
                {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m || arr[nx][ny] == 0 || ch[nx][ny] == 1)
                        continue;
                    q.push({nx, ny});
                    ch[nx][ny] = 1;
                }
            }
        }
    }
    cout << ans;
}
