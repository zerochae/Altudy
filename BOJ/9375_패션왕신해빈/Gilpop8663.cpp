#include <bits/stdc++.h>
using namespace std;

int t, n, k;

int memo[35][35];
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--)
    {
        map<string, int> s;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            string str1, str2;
            cin >> str1 >> str2;

            if (s.find(str2) != s.end())
            {
                s.find(str2)->second++;
            }
            else
            {
                s.insert({str2, 2});
            }
        }

        int ans = 1;
        for (auto iter = s.begin(); iter != s.end(); iter++)
        {
            ans *= iter->second;
        }

        ans -= 1;

        cout << ans << "\n";
    }
}
