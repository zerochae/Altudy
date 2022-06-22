#include <bits/stdc++.h>
using namespace std;

int t, n;

long long d[100005][4];

int mod = 1000000009;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    d[1][1] = 1;
    d[2][2] = 1;
    d[3][1] = 1;
    d[3][2] = 1;
    d[3][3] = 1;

    for (int i = 4; i < 100001; i++)
    {

        d[i][1] = (d[i - 1][2] + d[i - 1][3]) % mod;
        d[i][2] = (d[i - 2][1] + d[i - 2][3]) % mod;
        d[i][3] = (d[i - 3][1] + d[i - 3][2]) % mod;
        // cout << i << " " << d[i] << "\n";
    }

    while (t--)
    {
        cin >> n;
        long long ans = (d[n][1] + d[n][2] + d[n][3]) % mod;
        cout << ans << "\n";
    }
}
