#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[55][55];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = str[j] - '0';

            // cout << arr[i][j] << " ";
        }
        // cout << "\n";
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int num = arr[i][j];

            for (int k = 0; k < n; k++)
            {

                if (j + k >= m || i + k >= n)
                    continue;
                if (num != arr[i][j + k] || num != arr[i + k][j + k] || num != arr[i + k][j])
                    continue;

                // cout << i << "," << j << " " << i << "," << j + k << " " << i + k << "," << j + k << " " << i + k << "," << j << " " << num << " " << k << " " << k << "\n";
                ans = max(ans, (k + 1) * (k + 1));
            }
        }
    }

    if (ans == 0)
    {
        ans = 1;
    }

    cout << ans;
}
