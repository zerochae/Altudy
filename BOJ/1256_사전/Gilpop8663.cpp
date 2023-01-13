#include <bits/stdc++.h>
using namespace std;

int n, m, k;

long long dp[105][105];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    for (int i = 1; i <= 100; i++)
    {
        dp[i][0] = 1;
        dp[0][i] = 1;
    }

    for (int i = 1; i <= 100; i++)
    {
        for (int j = 1; j <= 100; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            if (dp[i][j] > 1000000000)
            {
                dp[i][j] = 1000000000;
            }
        }
    }

    if (dp[n][m] < k)
    {
        cout << -1;
        return 0;
    }

    int aCnt = n;
    int zCnt = m;

    for (int i = 0; i < n + m; i++)
    {
        int aStart = dp[aCnt - 1][zCnt];
        int zStart = dp[aCnt][zCnt - 1];

        if (aCnt == 0)
        {
            cout << 'z';
            zCnt -= 1;
            continue;
        }

        if (zCnt == 0)
        {
            cout << 'a';
            aCnt -= 1;
            continue;
        }

        if (k <= aStart)
        {
            cout << 'a';
            aCnt -= 1;
        }
        else
        {
            k = k - aStart;
            cout << 'z';
            zCnt -= 1;
        }
    }

    cout << "\n";
    return 0;
}