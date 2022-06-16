#include <bits/stdc++.h>
using namespace std;

int n, m;

map<string, string> s;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string http, id;

        cin >> http >> id;

        s.insert({http, id});
    }

    for (int i = 0; i < m; i++)
    {
        string http;
        cin >> http;

        if (s.find(http) != s.end())
        {
            cout << s.find(http)->second << "\n";
        }
    }
}
