#include <bits/stdc++.h>
using namespace std;

int n;

int arr[100005];

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

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << arr[n - i] << "\n";
    // }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, arr[n - i] * i);

        // cout << arr[i] << " " << arr[n - i] << "\n";
    }
    cout << ans;
    // w[n-k] * k;
    // 15 *1 15  10*2 20 3 30
}
