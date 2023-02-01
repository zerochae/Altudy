#include <bits/stdc++.h>
using namespace std;

int n;

string arr[15];

vector<int> ch;

set<char> s;

vector<char> strArr;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        for (int j = 0; j < arr[i].size(); j++)
        {
            char str = arr[i][j];
            s.insert(str);
        }
    }

    for (auto str : s)
    {
        strArr.push_back(str);
    }

    for (int i = 9; i >= 0; i--)
    {
        ch.push_back(i);
    }

    int realAns = 0;

    do
    {
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = 0; j < arr[i].size(); j++)
            {
                sum *= 10;
                char str = arr[i][j];
                for (int k = 0; k < strArr.size(); k++)
                {
                    if (strArr[k] == str)
                    {
                        sum += ch[k];
                        break;
                    }
                }
            }
            ans += sum;
        }

        realAns = max(realAns, ans);

    } while (prev_permutation(ch.begin(), ch.end()));

    cout << realAns;
}
