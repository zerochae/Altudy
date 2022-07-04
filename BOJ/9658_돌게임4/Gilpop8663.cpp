#include <bits/stdc++.h>
using namespace std;

int n;

int d[1005];

string ans[2] = {"SK", "CY"};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    d[1] = 1;
    d[2] = 0;
    d[3] = 1;
    d[4] = 0;
    for (int i = 5; i <= n; i++)
    {
        if (d[i - 1] == 1 || d[i - 3] == 1 || d[i - 4] == 1)
        {
            d[i] = 0;
        }
        else
        {
            d[i] = 1;
        }
    }

    cout << ans[d[n]];
}
