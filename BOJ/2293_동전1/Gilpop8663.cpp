#include <bits/stdc++.h>
using namespace std;

int n, k;

int d[10005];

int arr[10005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    d[0] = 1;
    for (int i = 1; i <= n; i++)

    {
        for (int j = arr[i]; j <= k; j++)
        {
            d[j] += d[j - arr[i]];
        }
        // cout << d[i] << "\n";
    }
    cout << d[k];
}
