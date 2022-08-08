#include <bits/stdc++.h>
using namespace std;

int n, m;

bool arr[55][55] = {0};

int ch[55][55] = {0};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<tuple<int, int, int>> q;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            if (str[j] == 'L')
            {
                arr[i][j] = 1;
            }
            else
            {
                arr[i][j] = 0;
            }
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int minNum = 0;

            fill(&ch[0][0], &ch[54][55], 0);

            if (arr[i][j] == 1)
            {
                ch[i][j] = 1;
                q.push({i, j, 1});
            }

            while (!q.empty())
            {
                tuple<int, int, int> cur = q.front();
                q.pop();

                int x = get<0>(cur);
                int y = get<1>(cur);
                int cnt = get<2>(cur);
                ch[x][y] = cnt;
                minNum = max(minNum, cnt);

                bool isFind = 0;
                for (int k = 0; k < 4; k++)
                {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (nx < 0 || ny < 0 || nx >= n || ny >= m || ch[nx][ny] >= 1 || arr[nx][ny] == 0)
                        continue;
                    isFind = 1;
                    ch[nx][ny] = 1;
                    q.push({nx, ny, cnt + 1});
                }
            }

            // for (int l = 0; l < n; l++)
            // {
            //     for (int w = 0; w < m; w++)
            //     {
            //         cout << ch[l][w] << " ";
            //     }
            //     cout << "\n";
            // }
            // cout << "\n";

            if (minNum != 999)
            {
                // cout << i << " " << j << " " << minNum << "\n";
                ans = max(ans, minNum);
            }
        }

        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < m; j++)
        //     {
        //         cout << ch[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
    }
    cout << ans - 1;
}