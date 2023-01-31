#include <bits/stdc++.h>
using namespace std;

int t, n;

const int MAX = 0x3f3f3f3f;

int arr[505];

int sum[505];
int dp[505][505];

int func(int a, int b) // a부터 b까지의 파일의 최소 용량
{
    if (dp[a][b] != MAX)
    {
        return dp[a][b];
    }

    if (a == b)
    {
        return dp[a][b] = 0;
    }

    if (a + 1 == b)
    {
        return dp[a][b] = arr[a] + arr[b];
    }

    for (int i = a; i < b; i++)
    {
        int left = func(a, i);
        int right = func(i + 1, b);
        dp[a][b] = min(dp[a][b], left + right);
    }

    return dp[a][b] += sum[b] - sum[a - 1];
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n;

        fill(&dp[0][0], &dp[504][505], MAX);

        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }

        for (int i = 1; i <= n; i++)
        {
            sum[i] = sum[i - 1] + arr[i];
        }

        int ans = func(1, n);


        cout << ans << "\n";
    }
}
