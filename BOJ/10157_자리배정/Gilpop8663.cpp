#include <bits/stdc++.h>
using namespace std;

int n, m, k;

int board[1005][1005];

bool ch[1005][1005];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

vector<int> a;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;

    cin >> k;

    int y = n - 1;

    int x = 0;

    int dir = 0;
    int retX, retY;
    for (int i = 1; i <= m * n; i++)
    {
        board[y][x] = i;

        if (i == k)
        {
            retX = x + 1;
            retY = n - y;
        }

        int nx = x + dx[dir];
        int ny = y + dy[dir];

        // cout << nx << " " << ny << " " << i << "\n";

        if (ny < 0 || nx < 0 || nx >= m || ny >= n || board[ny][nx] != 0)
        {
            dir = (dir + 1) % 4;
        }
        y = y + dy[dir];
        x = x + dx[dir];
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << board[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    if (n * m >= k)
    {
        cout << retX << " " << retY;
    }
    else
    {
        cout << 0;
    }
}
