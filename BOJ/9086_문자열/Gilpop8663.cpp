#include <bits/stdc++.h>
using namespace std;

int t;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        string str;
        cin >> str;

        string ans;

        ans += str[0];
        ans += str[str.size() - 1];
        cout << ans << "\n";
    }
}