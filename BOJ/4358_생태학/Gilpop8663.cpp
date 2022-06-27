#include <bits/stdc++.h>
using namespace std;

int n, a, b;

map<string, double> s;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;

    int cnt = 0;
    while (getline(cin, str))
    {

        // if (str == "s")
        //     break;
        cnt++;
        if (s.find(str) != s.end())
        {
            s.find(str)->second++;
        }
        else
        {
            s.insert({str, 1});
        }

        // cout << str << "\n";
    }

    cout << fixed;
    cout.precision(4);
    for (auto iter = s.begin(); iter != s.end(); iter++)
    {
        double number = iter->second / cnt * 100;
        cout << iter->first << " " << number << "\n";
        // cout << iter->first << " " << iter->second << " " << cnt << "\n";
    }
}
