#include <bits/stdc++.h>
using namespace std;

int t, n;

int d[3][100005];

int mod = 10007;

int arr[3][100005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;

        for (int i = 1; i <= 2; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> arr[i][j];
            }
        }

        for (int j = 1; j <= n + 1; j++)
        {
            for (int i = 0; i <= 2; i++)
            {
                if (i == 0)
                {
                    d[i][j] = max(d[0][j - 1], max(d[1][j - 1], d[2][j - 1]));
                }
                else if (i == 1)
                {
                    d[i][j] = max(d[2][j - 1], d[0][j - 1]) + arr[1][j - 1];
                }
                else if (i == 2)
                {
                    d[i][j] = max(d[1][j - 1], d[0][j - 1]) + arr[2][j - 1];
                }
                // cout << d[i][j] << "\n";
            }
        }

        cout << max({d[0][n + 1], d[1][n + 1], d[2][n + 1]}) << "\n";
    }
}
