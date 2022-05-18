#include <bits/stdc++.h>
using namespace std;

int n, m;
int d[100005];
int arr[100005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    d[1] = arr[1];
    /*
    d[2] = d[1] + arr[2];
    ...
    d[i]= d[i-1] + arr[i];
    */

    for (int i = 2; i <= n; i++)
    {
        d[i] = d[i - 1] + arr[i];
    }
    for (int i = 0; i < m; i++)
    {
        int st, en;
        int ans = 0;
        cin >> st >> en;
        ans = d[en] - d[st - 1];
        // cout << d[en] << " " << d[st - 1] << " ";
        cout << ans << "\n";
    }
}