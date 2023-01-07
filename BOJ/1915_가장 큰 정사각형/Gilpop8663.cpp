#include <bits/stdc++.h>
using namespace std;

int n, m;

#define X first
#define Y second

int arr[1005][1005];
int dp[1005][1005];
int tmp[1005][1005];

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
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1)
            {
                dp[i][j] = 1;
            }
        }
    }

    for (int k = 0; k < min(n, m); k++)
    {

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                tmp[i][j] = dp[i][j];
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (dp[i][j] == 0)
                    continue;
                int number = dp[i - 1][j];
                if (dp[i][j - 1] == number && dp[i - 1][j - 1] == number)
                {
                    tmp[i][j] = number + 1;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                dp[i][j] = tmp[i][j];
            }
        }
    }
    // cout << "\n";

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (ans < dp[i][j])
            {
                ans = dp[i][j];
            }
            // cout << dp[i][j] << " ";
        }
        // cout << "\n";
    }

    cout << ans * ans;
}
/*
6 6
010011
011111
011111
011111
011111
011111
*/