#include <bits/stdc++.h>
using namespace std;

int n, m;

map<string, int> s;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string str;

        cin >> str;

        // cout << s.find(str)->second << " " << str << "\n";
        if (s.find(str) != s.end())
        {
            s.find(str)->second += 1;
        }
        else
        {
            s.insert({str, 1});
        }
    }
    int ans = 0;
    string ansStr;

    // sort(s.begin(), s.end());

    for (auto i = s.begin(); i != s.end(); i++)
    {
        // cout << i->first << " " << i->second << "\n";
        if (ans < i->second)
        {
            ans = i->second;
            ansStr = i->first;
        }
    }

    cout << ansStr;
}
