#include <bits/stdc++.h>
using namespace std;

int n, s, m;

int arr[55];

int dp[55][1005];

int ans = -1e9;

int func(int k, int sum)
{
    if (sum > m)
        return -11;
    if (sum < 0)
        return -11;

    if (dp[k][sum] != -111)
    {
        return dp[k][sum];
    }

    if (k == n)
    {
        return sum;
    }

    dp[k][sum] = func(k + 1, sum + arr[k]);
    int tmp = -11;
    tmp = func(k + 1, sum - arr[k]);

    if (dp[k][sum] < tmp)
    {
        dp[k][sum] = tmp;
    }

    return dp[k][sum];
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < 52; i++)
    {
        for (int j = 0; j < 1002; j++)
        {
            dp[i][j] = -111;
        }
    }

    ans = func(0, s);

    if (ans < 0)
    {
        cout << -1;
        return 0;
    }
    cout << ans;
}
