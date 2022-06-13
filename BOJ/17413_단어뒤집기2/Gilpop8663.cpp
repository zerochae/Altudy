#include <bits/stdc++.h>
using namespace std;

string str;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cin.ignore();
    getline(cin, str);
    // cout << str;

    bool isTag = 0;
    vector<char> s;
    string ans;
    for (int i = 0; i < str.size(); i++)
    {

        if (str[i] == '<')
        {
            reverse(s.begin(), s.end());
            for (int i = 0; i < s.size(); i++)
            {
                ans += s[i];
            }
            ans += '<';
            s.clear();
            isTag = 1;
        }
        else if (str[i] == '>')
        {
            for (int i = 0; i < s.size(); i++)
            {
                ans += s[i];
            }
            ans += '>';
            s.clear();
            isTag = 0;
        }
        else if (isTag == 1 && str[i] == ' ')
        {
            for (int i = 0; i < s.size(); i++)
            {
                ans += s[i];
            }
            ans += ' ';
            s.clear();
        }
        else if (isTag == 0 && str[i] == ' ')
        {
            reverse(s.begin(), s.end());
            for (int i = 0; i < s.size(); i++)
            {
                ans += s[i];
            }
            ans += ' ';
            s.clear();
        }
        else
        {
            s.push_back(str[i]);
        }
    }

    if (s.size() > 1)
    {
        reverse(s.begin(), s.end());
        for (int i = 0; i < s.size(); i++)
        {
            ans += s[i];
        }
        s.clear();
    }

    cout << ans;
}
