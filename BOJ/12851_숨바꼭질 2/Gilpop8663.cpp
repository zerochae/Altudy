#include <bits/stdc++.h>
using namespace std;

int n, k;

int dp[100005];

queue<int> q;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;

    fill(dp, dp + 100005, 1e9);
    dp[n] = 0;

    q.push(n);

    int ans = 0;

    while (!q.empty())
    {
        int num = q.front();
        q.pop();

        if (num > 100000)
            continue;

        if (num == k)
        {
            ans += 1;
        }
        int minus = num - 1;
        int plus = num + 1;
        int multiply = num * 2;

        int nextTime = dp[num] + 1;

        if (dp[minus] >= nextTime && minus >= 0)
        {
            dp[minus] = nextTime;
            q.push(minus);
        }
        if (dp[plus] >= nextTime && plus < 100001)
        {
            dp[plus] = nextTime;
            q.push(plus);
        }
        if (multiply > 100001)
            continue;
        if (dp[multiply] >= nextTime)
        {
            dp[multiply] = nextTime;
            q.push(multiply);
        }
    }

    cout << dp[k] << "\n";
    cout << ans;
}
