#include <bits/stdc++.h>
using namespace std;

int t, n;

int d[10005][4];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    d[0][1] = 1;

    for (int i = 1; i < 10001; i++)
    {
        d[i][1] = d[i - 1][1];
        d[i][2] = d[i - 2][1] + d[i - 2][2];
        d[i][3] = d[i - 3][1] + d[i - 3][2] + d[i - 3][3];
    }

    while (t--)
    {
        cin >> n;

        int ans = d[n][1] + d[n][2] + d[n][3];

        cout << ans << "\n";
    }
}
