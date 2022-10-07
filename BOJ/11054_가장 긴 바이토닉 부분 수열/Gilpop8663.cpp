#include <bits/stdc++.h>
using namespace std;

int n;

int arr[1005];

int d[1005];
int dp[1005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        d[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                d[i] = max(d[j] + 1, d[i]);
            }
        }
        // cout << d[i] << " ";
    }

    // cout << "\n";
    for (int i = n - 1; i >= 0; i--)
    {
        dp[i] = 1;
        for (int j = i; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << dp[i] << " ";
    // }
    // cout << "\n";

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        // cout << d[i] << " " << dp[i] << "\n";
        ans = max(ans, d[i] + dp[i]);
    }
    cout << ans - 1;
}
