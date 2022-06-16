#include <bits/stdc++.h>
using namespace std;

string str;

map<char, int> arr;

vector<char> arr2;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;

    for (int i = 0; i < str.size(); i++)
    {

        if (arr.find(str[i]) != arr.end())
        {
            arr.find(str[i])->second++;
        }
        else
        {
            arr.insert({str[i], 1});
        }
    }
    int cnt = 0;

    string ans;
    char center;
    for (auto iter = arr.begin(); iter != arr.end(); iter++)
    {
        if (iter->second % 2 == 1)
        {
            center = iter->first;
            cnt++;
        }
    }

    if (cnt > 1)
    {
        cout << "I'm Sorry Hansoo";
    }
    else
    {
        for (auto iter = arr.begin(); iter != arr.end(); iter++)
        {
            for (int i = 0; i < iter->second / 2; i++)
            {
                arr2.push_back(iter->first);
            }
        }

        for (int i = 0; i < arr2.size(); i++)
        {
            ans += arr2[i];
        }

        if (str.size() % 2 == 1)
        {
            ans += center;
        }

        reverse(arr2.begin(), arr2.end());

        for (int i = 0; i < arr2.size(); i++)
        {
            ans += arr2[i];
        }

        cout << ans;
    }
}
