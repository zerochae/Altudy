#include <bits/stdc++.h>
using namespace std;

int n, k;

int arr[10005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    vector<int> dist;
    for (int i = 0; i < n - 1; i++)
    {
        dist.push_back(arr[i + 1] - arr[i]);
    }

    sort(dist.begin(), dist.end());

    int ans = 0;
    for (int i = 0; i < n - k; i++)
    {
        ans += dist[i];
    }

    cout << ans;
}
