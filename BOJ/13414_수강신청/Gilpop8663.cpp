#include <bits/stdc++.h>
using namespace std;

int k, n;

vector<string> ans;

string stu[500005];

unordered_map<string, int> arr;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k >> n;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        stu[i] = str;

        if (arr.find(str) != arr.end())
        {
            arr.find(str)->second++;
        }
        else
        {
            arr.insert({str, 1});
        }
    }

    for (int i = 0; i < n; i++)
    {
        string str = stu[i];

        if (arr.find(str)->second > 1)
        {
            arr.find(str)->second--;
        }
        else if (arr.find(str)->second == 1)
        {
            ans.push_back(str);
        }
    }
    int cnt = 0;
    for (int i = 0; i < ans.size(); i++)
    {
        if (cnt < k)
        {
            cout << ans[i] << "\n";
            cnt++;
        }
    }
}
