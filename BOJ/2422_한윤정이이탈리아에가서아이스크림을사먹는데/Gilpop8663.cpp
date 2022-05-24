#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[205][205];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;

        cin >> a >> b;

        if (a < b)
        {

            arr[a][b] = 1;
        }
        else
        {
            arr[b][a] = 1;
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n - 2; i++)
    {
        for (int j = i + 1; j <= n - 1; j++)
        {
            for (int k = j + 1; k <= n; k++)
            {

                if (arr[i][j] == 1 || arr[i][k] == 1 || arr[j][k] == 1)
                    continue;
                cnt++;
                // cout << i << " " << j << " " << k << "\n";
            }
        }
    }

    cout << cnt;
}
