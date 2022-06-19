#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[1005][1005];
int d[1005][1005];

int dx[3] = {1, 0, 1};
int dy[3] = {0, 1, 1};

int ans = 0;

// int func(int x, int y, int sum)
// {
//     if (x == n - 1 && y == m - 1)
//     {
//         ans = max(ans, sum);
//         return 0;
//     }

//     for (int k = 0; k < 3; k++)
//     {
//         int nx = x + dx[k];
//         int ny = y + dy[k];
//         if (nx < 0 || ny < 0 || nx >= n || ny >= m)
//             continue;
//         func(nx, ny, sum + arr[nx][ny]);
//     }
//     return 0;
// }

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
            d[i][j] = arr[i][j];
        }
    }

    // func(0, 0, arr[0][0]);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            d[i][j] = max(d[i][j - 1] + arr[i][j], max(d[i - 1][j] + arr[i][j], d[i - 1][j - 1] + arr[i][j]));
            // cout << d[i][j] << " ";
        }
        // cout << "\n";
    }

    ans = d[n][m];
    cout << ans;
}

/*
3 4
1 2 3 4
0 0 0 5
9 8 7 6


*/