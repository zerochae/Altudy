#include <bits/stdc++.h>
using namespace std;

int n, cur;

int arr[100005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> cur;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        arr[i] = abs(cur - num);
    }
    int ans = 1e9;

    for (int i = 0; i < n - 1; i++)
    {
        // cout << arr[i] << "\n";
        ans = min(ans, gcd(arr[i], arr[i + 1]));
    }

    if (n == 1)
    {
        ans = arr[0];
    }

    cout << ans << "\n";
}