#include <bits/stdc++.h>
using namespace std;

int t;

int x[4], y[4], s[6];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> t;

    while (t--)
    {
        k = 0;
        for (int i = 0; i < 4; i++)
        {
            cin >> x[i] >> y[i];
        }

        // for (int i = 0; i < 4; i++)
        // {
        //     cout << arr[i].first << " " << arr[i].second << "\n";
        // }

        for (int i = 0; i < 4; i++)
        {
            for (int j = i + 1; j < 4; j++)
            {
                s[k] = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
                k++;
            }
        }

        sort(s, s + 6);

        cout << (s[0] == s[1] && s[1] == s[2] && s[2] == s[3] && s[4] == s[5]) << "\n";
    }
}
