#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[1030][1030];

int d[1030][1030];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
            d[i][j] = d[i][j - 1] + d[i - 1][j] - d[i - 1][j - 1] + arr[i][j];
            // cout << d[i][j] << " ";
        }
        // cout << "\n";
    }
    int x1, x2, y1, y2;
    while (m--)
    { // 2,2  3,4;  9 + 14 + 21     14 + 21  5 + 7 + 9 + 11
        cin >> x1 >> y1 >> x2 >> y2;

        int ans = d[x2][y2] - d[x1 - 1][y2] - d[x2][y1 - 1] + d[x1 - 1][y1 - 1];
        cout << ans << "\n";
    }
}
