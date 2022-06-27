#include <bits/stdc++.h>
using namespace std;

string str;
bool ch[100];
bool markCh[100];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;

    int n = str.size();

    vector<int> num;
    vector<char> mark;
    string number;

    for (int i = 0; i < n; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            number += str[i];
        }
        else
        {
            num.push_back(stoi(number));
            mark.push_back(str[i]);
            number = "";
        }
    }

    if (number.size() > 0)
    {
        num.push_back(stoi(number));
        number = "";
    }

    vector<int> tmp;
    vector<char> newMark;
    for (int i = 0; i < mark.size(); i++)
    {
        if (ch[i] == 1 || ch[i + 1] == 1)
            continue;
        if (mark[i] == '+')
        {
            int sum = 0;
            int idx = i;
            while (true)
            {
                if (mark[idx] != '+' || idx > mark.size())
                {
                    sum += num[idx];
                    ch[idx] = 1;
                    break;
                }
                sum += num[idx];
                ch[idx] = 1;
                idx++;
            }

            tmp.push_back(sum);
        }
        else
        {
            ch[i] = 1;
            tmp.push_back(num[i]);
        }
    }

    for (int i = 0; i < num.size(); i++)
    {
        if (ch[i] == 0)
        {
            tmp.push_back(num[i]);
        }
    }

    // for (int i = 0; i < tmp.size(); i++)
    // {
    //     cout << tmp[i] << " ";
    // }
    // cout << "\n";

    // for (int i = 0; i < newMark.size(); i++)
    // {
    //     cout << newMark[i] << " ";
    // }
    // cout << "\n";

    int ans = tmp[0];

    for (int i = 1; i < tmp.size(); i++)
    {
        ans -= tmp[i];
    }

    cout << ans;
}
