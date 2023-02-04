#include <bits/stdc++.h>
using namespace std;

int n, m;

long long arr[10005];

// 100_000_000_000_000_000

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    long long ans = 0;

    if (n % 2 == 1)
    {
        for (int i = 0; i < n - 1; i += 2)
        {
            long long num = arr[i] + arr[n - 2 - i];
            ans = max(ans, num);
        }
        ans = max(ans, arr[n - 1]);
    }
    else
    {
        for (int i = 0; i < n; i += 2)
        {
            long long num = arr[i] + arr[n - 1 - i];
            ans = max(ans, num);
        }
    }

    cout << ans;
}
