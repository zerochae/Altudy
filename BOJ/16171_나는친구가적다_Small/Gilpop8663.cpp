#include <bits/stdc++.h>
using namespace std;

string str;

string s;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    cin >> str;

    string filter;
    for (int i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i]) == 0)
        {
            filter += s[i];
        }
    }

    if (filter.find(str) < 200)
    {
        cout << "1";
    }
    else
    {
        cout << "0";
    }

    // cout << filter;
}
