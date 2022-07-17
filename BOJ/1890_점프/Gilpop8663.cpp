#include <bits/stdc++.h>
using namespace std;

int n;

long long ans = 0;

int arr[105][105];
//  ch[105][105] = {0};
long long d[105][105];

queue<pair<int, int>> q;

long long DFS(int y, int x)
{

    if (y == n && x == n)
    {
        return 1;
    }

    if (y > n || x > n || arr[y][x] == 0)
        return 0;
    long long &ret = d[y][x];
    if (ret != -1)
        return ret;
    int res = arr[y][x];

    return ret = DFS(y + res, x) + DFS(y, x + res);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
            // d[i][j] = -1; // 방법 1
        }
    }

    // ans = DFS(1, 1); // 방법 1

    //방법2

    d[1][1] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (d[i][j] == 0 || (i == n && j == n))
                continue;
            long long value = arr[i][j];
            long long down = value + i;
            long long right = value + j;
            if (down <= n)
            {
                d[down][j] = d[down][j] + d[i][j];
            }
            if (right <= n)
            {
                d[i][right] = d[i][right] + d[i][j];
            }
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout << d[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    ans = d[n][n];

    cout << ans << "\n";
}
