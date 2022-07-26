#include <bits/stdc++.h>
using namespace std;

int n;

int arr[100005];
int sum[100005];
int ds[100005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        sum[i] = sum[i - 1] + arr[i];
    }

    int ans = 0;

    // 1. 벌 - 꿀통 - 벌

    for (int i = 2; i < n; i++)
    {
        int cur = (sum[i] - sum[1]) + (sum[n - 1] - sum[i - 1]);
        ans = max(ans, cur);
    }

    // 2. 벌 - 벌 - 꿀통

    for (int i = 2; i < n; i++)
    {
        int cur = (sum[n] - sum[1] - arr[i]) + (sum[n - 1] - sum[i]);
        ans = max(ans, cur);
    }

    // 3. 꿀통 - 벌 - 벌

    for (int i = 2; i < n; i++)
    {
        int cur = (sum[n - 1] - arr[i] + sum[i - 1]);
        ans = max(ans, cur);
    }

    cout << ans;
}
