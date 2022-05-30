#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, m;

string arr[100005];

pair<string, int> arr2[100005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    unordered_map<string, int> um;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        um.insert({arr[i], i + 1});
    }

    // sort(arr2, arr2 + n);

    for (int i = 0; i < m; i++)
    {
        string str;

        cin >> str;

        // cout << isdigit(str[0]) << "\n";

        if (isdigit(str[0]) == 1)
        {
            // cout << stoi(str) << "\n";
            cout << arr[stoi(str) - 1] << "\n";
            // cout << um.find(stoi(str) - 1);
        }
        else
        {
            // int st = 0, end = n, mid = (st + end) / 2;
            // while (true)
            // {
            //     if (str < arr2[mid].first)
            //     {
            //         end = mid;
            //     }
            //     else if (str > arr2[mid].first)
            //     {
            //         st = mid;
            //     }
            //     else
            //     {
            //         cout << arr2[mid].second << "\n";
            //         break;
            //     }
            //     mid = (st + end) / 2;
            // }
            auto it_2 = um.find(str);

            if (um.find(str) != um.end())
            {
                cout << it_2->second << "\n";
            }
        }
    }
}
