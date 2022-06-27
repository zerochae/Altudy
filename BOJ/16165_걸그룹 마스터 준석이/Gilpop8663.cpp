#include <bits/stdc++.h>
using namespace std;

int n, p;
map<string, vector<string>> teamArr;
map<string, string> member;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> p;

    // cout << n << " " << p << "\n";

    for (int i = 0; i < n; i++)
    {
        string team;

        int cnt;
        cin >> team >> cnt;
        vector<string> arr;
        for (int j = 0; j < cnt; j++)
        {
            string str;
            cin >> str;

            arr.push_back(str);

            member.insert({str, team});
        }

        sort(arr.begin(), arr.end());

        teamArr.insert({team, arr});
    }

    for (int i = 0; i < p; i++)
    {

        string str;

        int num;

        cin >> str >> num;

        if (num == 1)
        {
            cout << member.find(str)->second << "\n";
        }
        else
        {
            for (int j = 0; j < teamArr.find(str)->second.size(); j++)
            {
                cout << teamArr.find(str)->second[j] << "\n";
            }
        }
    }
}
