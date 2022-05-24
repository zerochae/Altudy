#include <bits/stdc++.h>
using namespace std;

int n, k;

int arr[55][55];

int d[55][55];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    d[0][0] = 1;
    d[1][1] = 1;

    for (int i = 0; i < n; i++)
    {
        d[i][0] = 1;
        d[i][i] = 1;
    }

    for (int i = 2; i < n; i++)
    {
        for (int j = 1; j < n - 1; j++)
        {
            d[i][j] = d[i - 1][j - 1] + d[i - 1][j];
        }
    }

    cout << d[n - 1][k - 1];
}
