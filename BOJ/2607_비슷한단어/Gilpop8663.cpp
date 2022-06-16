#include <bits/stdc++.h>
using namespace std;

int n;

string arr[105];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    string ori;
    cin >> ori;

    map<char, int> s;

    int ans = 0;

    for (int i = 0; i < ori.size(); i++)
    {
        // cout << ori[i] << "\n";
        if (s.find(ori[i]) != s.end())
        {
            s.find(ori[i])->second++;
        }
        else
        {
            s.insert({ori[i], 1});
        }
    }

    for (int i = 1; i < n; i++)
    {
        string str;
        map<char, int> m;

        set<char> ss;

        cin >> str;

        for (int j = 0; j < ori.size(); j++)
        {
            ss.insert(ori[j]);
        }

        for (int j = 0; j < str.size(); j++)
        {
            ss.insert(str[j]);
        }

        for (int j = 0; j < str.size(); j++)
        {
            if (m.find(str[j]) != m.end())
            {
                m.find(str[j])->second++;
            }
            else
            {
                m.insert({str[j], 1});
            }
        }

        int cnt = 0;

        // cout << str << "\n";
        for (auto word : ss)
        {
            // cout << word << " ";
            // cout << s.find(word)->second << " " << m.find(word)->second << "\n";
            if (s.find(word)->second == m.find(word)->second)
                continue;
            else
            {
                cnt += abs(m.find(word)->second - s.find(word)->second);
            }
        }

        // cout << cnt;
        if (str.size() == ori.size() && cnt <= 2)
        {
            ans++;
            // cout << str << "\n";
        }
        else if (cnt < 2)
        {

            ans++;
            // cout << str << "\n";
        }
        // cout
        //     << "\n";
    }

    cout << ans;
}

/*

반례

10
ABAAC
ABAA
ABAC
ABAB
ABAAA
ABCAA
ABSAC
AABBB
AA
ABC


정답 :

ABAA
ABAC
ABAAA
ABCAA
ABSAC



답 : 5

*/