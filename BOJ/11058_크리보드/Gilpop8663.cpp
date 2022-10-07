#include <bits/stdc++.h>
using namespace std;

int n;

int ansNum = 0;

long long dp[101];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i - 1] + 1;
        for (int j = 3; j <= i; j++)
        {
            dp[i] = max(dp[i], dp[i - j] * (j - 1));
        }
    }

    cout << dp[n];
}
