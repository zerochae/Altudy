#include <bits/stdc++.h>
using namespace std;

int n;

map<string, int> arr;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        if (arr.find(str) != arr.end())
        {
            arr.find(str)->second++;
        }
        else
        {
            arr.insert({str, 1});
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        string str;
        cin >> str;

        arr.find(str)->second--;
    }

    for (auto iter = arr.begin(); iter != arr.end(); iter++)
    {
        if (iter->second != 0)
        {
            cout << iter->first;
        }
    }

    return 0;
}