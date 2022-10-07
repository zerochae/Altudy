#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[100005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int st = 0;
    int end = 0;

    int ans = 2e9;
    while (st < n && end < n)
    {
        int result = arr[end] - arr[st];
        if (result < m)
        {
            end++;
        }
        else
        {
            ans = min(ans, result);
            st++;
        }
    }

    cout << ans;
}
