#include <bits/stdc++.h>
using namespace std;

string s1;
string s2;

set<string> s;

int d[4001][4001];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s1 >> s2;

    int ans = 0;

    for (int i = 0; i < s1.size(); i++)
    {
        for (int j = 0; j < s2.size(); j++)
        {
            if (s1[i] == s2[j])
            {
                d[i][j] = 1;

                if (i >= 1 && j >= 1)
                {
                    d[i][j] += d[i - 1][j - 1];
                }
                ans = max(ans, d[i][j]);
            }
        }
    }

    cout << ans;
}
