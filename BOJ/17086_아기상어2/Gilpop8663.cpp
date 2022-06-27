#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[55][55];
int arr2[55][55];

int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, -1, 1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    queue<tuple<int, int, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            arr2[i][j] = 99;
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            bool ch[55][55] = {0};

            bool isFind = 0;

            if (arr[i][j] == 1)
            {
                q.push({i, j, 0});
                arr2[i][j] = 0;
                ch[i][j] = 1;
            }

            while (!q.empty())
            {
                tuple<int, int, int> cur = q.front();
                q.pop();

                int x = get<0>(cur);
                int y = get<1>(cur);
                int cnt = get<2>(cur);

                for (int k = 0; k < 8; k++)
                {

                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (ch[nx][ny] == 1)
                        continue;

                    if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                        continue;
                    if (arr[nx][ny] == 0)
                    {
                        ch[nx][ny] = 1;
                        q.push({nx, ny, cnt + 1});
                        arr2[nx][ny] = min(arr2[nx][ny], cnt + 1);
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // cout << arr2[i][j] << " ";
            ans = max(arr2[i][j], ans);
        }
        // cout << "\n";
    }

    cout << ans << "\n";
}