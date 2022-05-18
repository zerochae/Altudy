#include <bits/stdc++.h>
using namespace std;

int n;

int mod = 1000000000;

int d[10000005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    d[0] = 0;
    d[1] = 1;

    // d[1] = d[0] - d[-1];
    // d[-1] = 1;

    // d[0] = d[-1] + d[-2];

    // d[-2] = -1;

    // d[-1] = d[-2] + d[-3];

    // d[i] = d[i-1] -d[i-2];
    // d[-3] = d[-1] - d[-2];
    // d[-3] = 2;
    for (int i = 2; i <= abs(n); i++)
    {
        d[i] = (d[i - 1] + d[i - 2]) % mod;
    }

    if (n > 0)
    {
        cout << 1 << "\n";
    }
    else if (n == 0)
    {

        cout << 0 << "\n";
    }
    else
    {
        if (abs(n) % 2 == 0)
        {
            cout << -1 << "\n";
        }

        else
        {
            cout << 1 << "\n";
        }
    }
    cout << d[abs(n)];
}
