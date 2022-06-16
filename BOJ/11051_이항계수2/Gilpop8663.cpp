#include <bits/stdc++.h>
using namespace std;

int n, k;

int memo[1005][1005];

int mod = 10007;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;

    memo[1][0] = 1;
    memo[1][1] = 1;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            if (i == j || j == 0)
            {
                memo[i][j] = 1;
            }
            else
            {
                memo[i][j] = memo[i - 1][j] % mod + memo[i - 1][j - 1] % mod;
            }
        }
    }
    int ans = memo[n][k] % mod;

    cout << ans;
}
