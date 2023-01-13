#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[2005];

int dp[2005][2005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        dp[i][i] = 1;
    }

    for (int i = 1; i <= n - 1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            dp[i][i + 1] = 1;
        }
    }

    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = i + 2; j <= n; j++)
        {
            if (arr[i] == arr[j] && dp[i + 1][j - 1] == 1)
            {
                dp[i][j] = 1;
            }
        }
    }

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int st, en;
        cin >> st >> en;
        cout << dp[st][en] << "\n";
    }
}
