#include <bits/stdc++.h>
using namespace std;

int n, k;
// 2000000000
int d[35];

int arr[35];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (k >= arr[i])
        {
            ans += k / arr[i];
            k = k % arr[i];
        }
    }
    cout << ans;
}
