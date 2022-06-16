#include <bits/stdc++.h>
using namespace std;

int t, n;

int arr[105];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;

    while (t--)
    {
        cin >> n;

        long long ans = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                ans += gcd(arr[i], arr[j]);
                // cout << arr[i] << " " << arr[j] << "\n";
            }
        }
        cout << ans;
        cout << "\n";
    }
}
