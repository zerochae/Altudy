#include <bits/stdc++.h>
using namespace std;

int n;

bool ch[4000005];

int dp[283156];

vector<int> decimal;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    ch[1] = 1;
    for (int i = 2; i * i <= n; i++)
    {
        if (ch[i] == 1)
            continue;
        for (int j = i * 2; j <= n; j += i)
        {
            ch[j] = 1;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (ch[i] == 1)
            continue;
        decimal.push_back(i);
        // cout << i << " ";
    }

    int ans = 0;

    int st = 0, en = 0;
    int sum = 0;

    while (1)
    {
        // cout << sum << " " << st << " " << en << "\n";
        if (sum > n)
        {
            sum -= decimal[st];
            st += 1;
        }
        else if (sum < n)
        {
            if (en >= decimal.size())
                break;
            sum += decimal[en];
            en += 1;
        }
        else if (sum == n)
        {
            ans += 1;
            if (en >= decimal.size())
                break;
            sum += decimal[en];
            en += 1;
        }
    }
    cout << ans;
}
