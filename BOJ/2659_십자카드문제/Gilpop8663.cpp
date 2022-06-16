#include <bits/stdc++.h>
using namespace std;

int arr[5];
string ans;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> tmpp;

    for (int i = 0; i < 4; i++)
    {
        cin >> arr[i];
    }

    tmpp.push_back(arr[0] * 1000 + arr[1] * 100 + arr[2] * 10 + arr[3]);
    tmpp.push_back(arr[1] * 1000 + arr[2] * 100 + arr[3] * 10 + arr[0]);
    tmpp.push_back(arr[2] * 1000 + arr[3] * 100 + arr[0] * 10 + arr[1]);
    tmpp.push_back(arr[3] * 1000 + arr[0] * 100 + arr[1] * 10 + arr[2]);

    sort(tmpp.begin(), tmpp.end());

    string ans = to_string(tmpp[0]);

    set<string> s;
    int cnt = 0;
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            for (int k = 1; k <= 9; k++)
            {
                for (int m = 1; m <= 9; m++)
                {
                    vector<int> tmp;

                    tmp.push_back(i * 1000 + j * 100 + k * 10 + m);
                    tmp.push_back(j * 1000 + k * 100 + m * 10 + i);
                    tmp.push_back(k * 1000 + m * 100 + i * 10 + j);
                    tmp.push_back(m * 1000 + i * 100 + j * 10 + k);

                    sort(tmp.begin(), tmp.end());

                    string str = to_string(tmp[0]);

                    // cout << str << "\n";
                    s.insert(str);
                    // if (arr[0] == i && arr[1] == j && arr[2] == k && arr[3] == m)
                    // {
                    //     cout << cnt;
                    //     return 0;
                    // }
                    // cnt++;
                }
            }
        }
    }

    for (auto str : s)
    {
        cnt++;
        // cout << str << " " << ans << "\n";
        if (ans == str)
        {
            cout << cnt;
            break;
        }
    }
}
