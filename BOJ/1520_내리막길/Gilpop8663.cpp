#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[505][505];
int dp[505][505];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int func(int x, int y)
{

    // cout << x << " " << y << "\n";
    if (x == n - 1 && y == m - 1)
    {
        return 1;
    }

    if (dp[x][y] != -1)
        return dp[x][y];

    dp[x][y] = 0;

    for (int k = 0; k < 4; k++)
    {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
            continue;
        if (arr[x][y] > arr[nx][ny])
        {
            dp[x][y] = dp[x][y] + func(nx, ny);
        }
    }

    return dp[x][y];
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            dp[i][j] = -1;
        }
    }

    int ans = func(0, 0);

    cout << ans;
}
