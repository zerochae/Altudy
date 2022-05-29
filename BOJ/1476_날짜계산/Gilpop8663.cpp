#include <bits/stdc++.h>
using namespace std;

int e, s, m;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> e >> s >> m;

    int n = 1, b = 1, k = 1;

    int cnt = 1;
    while (true)
    {
        if (n == e && b == s && m == k)
        {
            break;
        }
        if (n >= 15)
        {
            n = 1;
        }
        else
        {
            n++;
        }

        if (b >= 28)
        {
            b = 1;
        }
        else
        {
            b++;
        }

        if (k >= 19)
        {
            k = 1;
        }
        else
        {
            k++;
        }
        cnt++;
    }
    // cout << cnt << " " << n << " " << b << " " << k << "\n";
    cout << cnt;
}
