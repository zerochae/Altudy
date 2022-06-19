#include <bits/stdc++.h>
using namespace std;

int t, n;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    for (int j = 0; j < t; j++)
    {
        cin >> n;

        int tCnt = 0;
        int fCnt = 0;

        int num1 = n;
        int num2 = n;
        int tpow = 2;
        int fpow = 5;

        while (tpow <= n && fpow <= n)
        {
            tCnt += n / tpow;
            tpow *= 2;
            fCnt += n / fpow;
            fpow *= 5;
        }

        int ans = min(tCnt, fCnt);

        cout << ans << "\n";
    }
}
