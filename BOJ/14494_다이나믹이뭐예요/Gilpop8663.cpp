#include <bits/stdc++.h>

using namespace std;

int n, m;

int mod = 1000000007;

int d[1005][1005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            d[i][j] = 1;
            int num = (((d[i - 1][j] + d[i - 1][j - 1]) % mod) + d[i][j - 1]) % mod;
            d[i][j] = max(d[i][j], num);
            // cout << d[i][j] << " ";
        }
        // cout << "\n";
    }
    cout << d[n][m];
}