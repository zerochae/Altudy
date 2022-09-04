#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[505];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int ans = 0;

    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i < m - 1; i++)
    {
        int left = 0, right = 0;

        for (int j = 0; j < i; j++)
        {
            left = max(left, arr[j]);
        }
        for (int j = i + 1; j < m; j++)
        {
            right = max(right, arr[j]);
        }

        ans += max(0, min(left, right) - arr[i]);
    }
    cout << ans;
}
