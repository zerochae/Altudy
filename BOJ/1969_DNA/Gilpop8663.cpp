#include <bits/stdc++.h>
using namespace std;

int n, m;

string arr[1005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    string ans;

    int ansNum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < m; i++)
    {
        vector<pair<char, int>> hd;
        for (int j = 0; j < n; j++)

        {
            int sear = 0;
            bool flag = false;

            // cout << arr[j][i];
            for (int k = 0; k < hd.size(); k++)
            {
                if (hd[k].first == arr[j][i])
                {
                    sear = k;
                    flag = true;
                }
            }

            if (flag == true)
            {
                hd[sear].second++;
            }
            else
            {
                hd.push_back({arr[j][i], 1});
            }
        }

        sort(hd.begin(), hd.end());

        int max = 0;
        char str;
        for (int i = 0; i < hd.size(); i++)
        {
            if (max < hd[i].second)
            {
                max = hd[i].second;
                str = hd[i].first;
            }
        }
        // cout << str << " " << max << "\n";
        ans += str;
        ansNum += n - max;
    }

    cout << ans << "\n"
         << ansNum;
}
