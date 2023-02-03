#include <bits/stdc++.h>
using namespace std;

string str1, str2;

int dp[1005][1005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str1 >> str2;

    string arr = "0" + str1;
    string arr2 = "0" + str2;

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr2.size(); j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
                continue;
            }

            if (arr[i] == arr2[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    stack<int> s;

    int i = arr.size() - 1;
    int j = arr2.size() - 1;

    while (dp[i][j] != 0)
    {
        if (dp[i][j] == dp[i][j - 1])
        {
            j--;
        }
        else if (dp[i][j] == dp[i - 1][j])
        {
            i--;
        }
        else if (dp[i - 1][j - 1] + 1 == dp[i][j])
        {
            s.push(i);
            i--;
            j--;
        }
    }

    cout << dp[arr.size() - 1][arr2.size() - 1] << "\n";

    while (!s.empty())
    {
        cout << arr[s.top()];
        s.pop();
    }
}
