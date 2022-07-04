#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[2005][2005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int ans = 0;

    for (int i = n; i <= m; i++)
    {

        // int deg = 36000 / i;

        for (int j = 1; j <= i; j++)
        {
            // int tmp = deg * j;

            int c = gcd(i, j);

            // cout << c << "\n";

            int x = i / c;
            int y = j / c;

            if (arr[x][y] == 0)
            {
                arr[x][y] = 1;
                ans++;
            }
            // cout << x << " " << y << "\n";

            // cout << i << " " << j * c << " " << c << " ";
        }
        // cout << "\n";
    }

    cout << ans << "\n";
}
