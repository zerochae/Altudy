#include <bits/stdc++.h>
using namespace std;

int n;

int d[1005][10];

int mod = 10007;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    // for (int i = 0; i <= 9; i++)
    // {
    //     d[1][i] = 1;
    // }

    d[0][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            for (int k = 0; k <= 9; k++)
            {
                if (k <= 9 - j)
                {
                    d[i][9 - j] += d[i - 1][k];
                }
                d[i][9 - j] %= mod;
            }
            // d[2][1] = 2
            // cout << d[i][9 - j] << "\n";
        }
    }

    int ans = 0;

    for (int i = 0; i <= 9; i++)
    {
        ans += d[n][i];
        ans %= mod;
    }
    cout << ans;
}
