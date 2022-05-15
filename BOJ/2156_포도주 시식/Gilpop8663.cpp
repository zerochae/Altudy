#include <bits/stdc++.h>
using namespace std;

int n;
// 2000000000
int d[10005][3];

int arr[10005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    d[0][1] = arr[0];
    d[0][2] = 0;
    d[1][1] = arr[1];
    d[1][2] = d[0][1] + arr[1];
    // d[2][1] = max(d[0][1], d[0][2])

    for (int i = 2; i < n; i++)
    {
        for (int j = 2; j <= i; j++)
        {
            d[i][1] = max({d[i][1], d[i - j][1], d[i - j][2]});
        }
        d[i][1] += arr[i];
        d[i][2] = d[i - 1][1] + arr[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max({ans, d[i][1], d[i][2]});
    }
    cout << ans << "\n";
}
