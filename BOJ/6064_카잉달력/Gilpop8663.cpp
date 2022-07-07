#include <bits/stdc++.h>
using namespace std;

int t, n, m, x, y;

int arr[100005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while (t--)
    {
        int i;
        cin >> m >> n >> x >> y;

        // cout << gcd(n, m) << " ";
        int limit = lcm(m, n);

        // cout << limit << "\n";

        for (i = x; i <= limit; i += m)
        {
            int tmp = (i % n == 0) ? n : i % n;
            if (tmp == y)
            {
                cout << i << "\n";
                break;
            }
        }

        // cout << i << "\n";

        if (i > limit)
        {
            cout << -1 << "\n";
        }
    }
}
