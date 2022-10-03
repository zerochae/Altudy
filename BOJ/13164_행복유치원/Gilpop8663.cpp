#include <bits/stdc++.h>
using namespace std;

int n, k;

int arr[300005];

vector<int> cost;

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

    for (int i = 1; i < n; i++)
    {
        cost.push_back(arr[i] - arr[i - 1]);
    }

    long long ans = 0;
    sort(cost.begin(), cost.end());

    for (int i = 0; i < n - k; i++)
    {
        ans += cost[i];
    }
    cout << ans;
}
