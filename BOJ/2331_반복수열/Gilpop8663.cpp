#include <bits/stdc++.h>
using namespace std;

int n, m;

vector<int> d;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int cnt = 0;

    d.push_back(n);

    for (int i = 1; i < 9999; i++)
    {

        bool flag = 0;

        string str = to_string(d[i - 1]);

        int ans = 0;

        for (int j = 0; j < str.size(); j++)
        {
            int num = 1;
            for (int k = 0; k < m; k++)
            {
                num *= str[j] - '0';
            }
            ans += num;
        }
        // cout << ans << " " << i << " " << str << "\n";

        for (int z = 0; z < d.size(); z++)
        {
            if (d[z] == ans)
            {
                cnt = z;
                flag = 1;
                break;
            }
        }

        if (flag == 1)
            break;

        d.push_back(ans);
    }
    cout << cnt << "\n";
    // cout << d.size();
}