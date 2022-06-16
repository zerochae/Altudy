#include <bits/stdc++.h>
using namespace std;

long long n, k;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true)
    {
        cin >> n >> k;

        if (n == 0 && k == 0)
            break;

        if (k > n - k)
        {
            k = n - k;
        }

        long long ans = 1;
        for (int i = 1; i <= k; i++)
        {
            ans = ans * (n - k + i) / i;
        }

        // long long num = 1;
        // for (int i = k; i >= 1; i--)
        // {
        //     num *= i;
        // }

        // ans /= num;

        cout << ans << "\n";
    }
}
