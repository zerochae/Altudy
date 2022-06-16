#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[100005];
int d[100005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    d[1] = arr[1];
    for (int i = 2; i <= n; i++)
    {
        d[i] = d[i - 1] + arr[i];
    }

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int st, en;
        cin >> st >> en;

        int ans = d[en] - d[st - 1];

        cout << ans << "\n";
    }
}
