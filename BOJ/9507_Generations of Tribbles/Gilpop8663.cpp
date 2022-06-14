#include <bits/stdc++.h>
using namespace std;

int t, n;

long long d[75];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;

    d[0] = 1;
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;

    for (int i = 4; i < 68; i++)
    {
        d[i] = d[i - 1] + d[i - 2] + d[i - 3] + d[i - 4];
    }

    // cout << d[8];

    while (t--)
    {

        cin >> n;

        cout << d[n] << "\n";
    }
}
