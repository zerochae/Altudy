#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    cin >> str;

    string ans = "";
    for (int i = 0; i < str.size(); i++)
    {
        if (isupper(str[i]))
            ans += tolower(str[i]);
        else if (islower(str[i]))
            ans += toupper(str[i]);
    }

    cout << ans;
}
