#include <bits/stdc++.h>

using namespace std;

int n;

int d[105][10];

int mod = 1000000000;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= 9; i++)
    {
        d[1][i] = 1;
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            if (j == 0)
            {
                d[i][j] = d[i - 1][j + 1];
            }
            else if (j == 9)
            {
                d[i][j] = d[i - 1][j - 1];
            }
            else if (j == 1)
            {
                if (d[i - 1][j - 1] == 0)
                {
                    d[i][j] = d[i - 1][j + 1] + 1;
                }
                else
                {
                    d[i][j] = d[i - 1][j - 1] + d[i - 1][j + 1];
                }
            }
            else
            {
                d[i][j] = d[i - 1][j - 1] + d[i - 1][j + 1];
            }
            d[i][j] = d[i][j] % mod;
        }
    }

    int tot = 0;
    for (int i = 1; i <= 9; i++)
    {
        tot += d[n][i];
        tot %= mod;
    }
    cout << tot;
}