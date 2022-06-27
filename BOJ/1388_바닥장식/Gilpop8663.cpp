#include <bits/stdc++.h>
using namespace std;

int n, m;

int board[55][55];
bool ch[55][55] = {0};

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
            if (str[j] == '-')
            {
                board[i][j] = 1;
            }
            else if (str[j] == '|')
            {
                board[i][j] = 2;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            queue<pair<int, int>> q;

            int num = board[i][j];

            // cout << num << " " << ch[i][j] << "\n";
            if (ch[i][j] == 0)
            {
                ch[i][j] = 1;
                q.push({i, j});
                ans++;
            }

            while (!q.empty())
            {
                int nx, ny;
                pair<int, int> cur = q.front();

                q.pop();

                if (num == 1)
                {
                    nx = cur.first;
                    ny = cur.second + 1;
                }

                if (num == 2)
                {
                    nx = cur.first + 1;
                    ny = cur.second;
                }

                // cout << nx << " " << ny << "\n";

                if (nx < 0 || ny < 0 || nx >= n || ny >= m || board[nx][ny] == 0)
                    continue;

                // cout << num << " " << board[nx][ny] << "\n";
                if (num == board[nx][ny])
                {
                    ch[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    cout << ans;
}