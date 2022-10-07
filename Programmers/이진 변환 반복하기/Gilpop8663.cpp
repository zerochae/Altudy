#include <bits/stdc++.h>

using namespace std;

string func(int k)
{
    string str;
    while (1)
    {
        if (k <= 1)
        {
            if (k == 1)
            {
                str += '1';
            }
            else
            {
                str += '0';
            }

            break;
        }

        if (k % 2 == 0)
        {
            str += '0';
        }
        else if (k % 2 == 1)
        {
            str += '1';
        }

        k /= 2;
    }

    reverse(str.begin(), str.end());

    cout << str << "\n";
    return str;
}

vector<int> solution(string s)
{
    vector<int> answer;

    int cnt = 0;

    int wow = 0;

    while (s.size() > 1)
    {
        string tmp;
        wow++;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
            {
                tmp += s[i];
            }
            else
            {
                cnt++;
            }
        }

        s = func(tmp.size());
    }

    answer.push_back(wow);
    answer.push_back(cnt);
    return answer;
}