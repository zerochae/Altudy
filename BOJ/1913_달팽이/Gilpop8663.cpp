#include <bits/stdc++.h>
using namespace std;

int n, m;

int board[1005][1005], retX, retY, x, y, dir;

const int dy[4] = {1, 0, -1, 0};
const int dx[4] = {0, 1, 0, -1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    // cout << n << "\n";

    for (int i = n * n; i > 0; i--)
    {

        // cout << x << " " << y << "\n";
        board[y][x] = i;

        if (i == m)
        {
            retX = x + 1;
            retY = y + 1;
        }
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (y + dy[dir] < 0 || y + dy[dir] >= n || x + dx[dir] < 0 || x + dx[dir] >= n || board[y + dy[dir]][x + dx[dir]] != 0)
        {
            dir = (dir + 1) % 4;
        }
        y = y + dy[dir];
        x = x + dx[dir];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }

    cout << retY << " " << retX << "\n";
    return 0;
}