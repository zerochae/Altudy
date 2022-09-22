#include <bits/stdc++.h>

using namespace std;

int n, m;

int arr[305][305];
int d[305][305];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            d[i][j] = max(d[i - 1][j] + arr[i][j], d[i][j - 1] + arr[i][j]);
        }
    }

    cout << d[n][m];
}