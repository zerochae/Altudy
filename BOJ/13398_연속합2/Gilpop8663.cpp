#include <bits/stdc++.h>
using namespace std;

int n;

int arr[100005];

int left_sum[100005];
int right_sum[100005];

int ans = -1e9;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    left_sum[0] = arr[0];
    ans = arr[0];
    right_sum[n - 1] = arr[n - 1];
    for (int i = 1; i < n; i++)
    {
        left_sum[i] = max(left_sum[i - 1] + arr[i], arr[i]);
        ans = max(ans, left_sum[i]);
    }

    for (int i = n - 2; i >= 0; i--)
    {
        right_sum[i] = max(right_sum[i + 1] + arr[i], arr[i]);
    }

    for (int i = 1; i < n - 1; i++)
    {
        ans = max(left_sum[i - 1] + right_sum[i + 1], ans);
    }

    cout << ans;
}
