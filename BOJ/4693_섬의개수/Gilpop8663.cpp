#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[60][60];

int dx[8] = {1, 1, 0, -1, 1, -1, -1, 0};
int dy[8] = {0, 1, 1, -1, -1, 1, 0, -1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> n >> m)
    {
        queue<pair<int, int>> q;
        bool ch[60][60] = {0};

        if (n == 0 && m == 0)
            break;

        int ans = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] == 1 && ch[i][j] == 0)
                {
                    ch[i][j] = 1;
                    q.push({i, j});
                    ans++;
                }

                while (!q.empty())
                {
                    pair<int, int> cur = q.front();
                    q.pop();

                    for (int k = 0; k < 8; k++)
                    {

                        int nx = cur.first + dx[k];
                        int ny = cur.second + dy[k];

                        if (nx < 0 || ny < 0 || nx >= m || ny >= n || ch[nx][ny] == 1)
                            continue;
                        if (arr[nx][ny] == 1)
                        {
                            q.push({nx, ny});
                            ch[nx][ny] = 1;
                        }
                    }
                }
            }
        }

        cout << ans << "\n";

        // for (int i = 0; i < m; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         cout << ch[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "\n";
    }
}
