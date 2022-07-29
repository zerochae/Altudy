#include <bits/stdc++.h>
using namespace std;

int n, m, k;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int board[205][205];
int ch[205][205];

queue<pair<int, int>> q;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            if (str[j] == '.')
            {
                board[i][j] = 1;
            }
            else
            {
                board[i][j] = 2;
                ch[i][j] = 1;
            }
        }
    }

    // k -= k / 3;

    for (int t = 2; t <= k; t++)

    {

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                if (board[i][j] == 2 && ch[i][j] < 3)
                {

                    ch[i][j]++;
                    if (ch[i][j] == 3)
                    {

                        ch[i][j] = 0;
                        board[i][j] = 1;
                        q.push({i, j});
                    }
                    continue;
                }

                if (board[i][j] == 1)
                {
                    board[i][j] = 2;
                }
            }
        }

        while (!q.empty())
        {
            pair<int, int> cur = q.front();

            q.pop();
            int x = cur.first;
            int y = cur.second;

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;

                ch[nx][ny] = 0;
                board[nx][ny] = 1;
            }
        }

        // cout << "\n";
        // cout << t << " "
        //      << "\n";
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < m; j++)
        //     {
        //         cout << board[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 1)
            {
                cout << '.';
            }
            else
            {
                cout << 'O';
            }
        }
        cout << "\n";
    }
}
