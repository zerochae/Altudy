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
        bool isNext = 0;
        string word;
        for (int j = 0; j < str.size(); j++)
        {

            if (isNext == 1)
            {
                word += str[j];
            }
            if (str[j] == '.')
            {
                isNext = 1;
            }
        }

        if (arr.find(word) != arr.end())
        {
            arr.find(word)->second++;
        }
        else
        {
            arr.insert({word, 1});
        }
    }

    for (auto iter = arr.begin(); iter != arr.end(); iter++)
    {
        cout << iter->first << " " << iter->second << "\n";
    }
}
