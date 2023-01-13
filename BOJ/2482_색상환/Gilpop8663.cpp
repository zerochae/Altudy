#include <bits/stdc++.h>
using namespace std;

int n, k;

int dp[1005][1005]; // n개의 색, k개를 고름

const int MOD = 1000000003;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 0; i <= n; i++)
    {
        dp[i][1] = i;
        dp[i][0] = 1;
    }

    for (int i = 4; i <= n; i++)
    {
        for (int j = 2; j <= k; j++)
        {
            dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % MOD;
        }
    }

    int ans = dp[n][k];

    cout << ans;
}
