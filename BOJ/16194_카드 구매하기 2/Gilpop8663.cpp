#include <bits/stdc++.h>

using namespace std;

int t;
int n;

int arr[10005];
int d[10005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++)
    {

        d[i] = arr[i];

        for (int j = 1; j < i; j++)
        {

            d[i] = min(d[j] + arr[i - j], d[i]);
        }
        // cout << d[i] << " ";
    }

    int ans = d[n];

    cout << ans;
}
