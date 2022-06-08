#include <bits/stdc++.h>
using namespace std;

int n;

long long d[500005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    d[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        long long sum = 0;
        for (int j = 0; j < i; j++)
        {
            // cout << d[j] << " " << d[i - 1 - j] << "\n";
            sum += d[j] * d[i - 1 - j];
        }
        d[i] = sum;

        // cout << d[i] << " " << sum << "\n";
    }

    cout << d[n];
}
