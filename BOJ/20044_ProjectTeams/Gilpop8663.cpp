#include <bits/stdc++.h>
using namespace std;

int n;

int arr[10005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    n = n * 2;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int ans = 299999;
    for (int i = 0; i < n / 2; i++)
    {
        // cout << arr[i] << " " << arr[n - 1 - i] << "\n";
        ans = min(ans, arr[i] + arr[n - 1 - i]);
    }
    cout << ans;
}