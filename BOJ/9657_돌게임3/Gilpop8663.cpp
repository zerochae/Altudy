#include <bits/stdc++.h>
using namespace std;

int n;

int d[1005]; // 돌이 i개 있을 때 선공이 이기면 0, 후공이 이기면 1
string ans[] = {"SK", "CY"};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    fill(d, d + 1005, -1);
    d[1] = 0; // sk
    d[2] = 1; // cy 1+1
    d[3] = 0; // sk 1+ 1+1
    d[4] = 0; // cy

    int a[3] = {1, 3, 4};

    for (int i = 5; i <= n; i++)
    {
        for (int j : a)
        {
            if (d[i - j] == 1)
            {
                d[i] = 0;
                break;
            }
            else
            {
                d[i] = 1;
            }
        }
    }

    // for (int i = 0; i <= n; i++)
    // {
    //     cout << d[i] << " ";
    // }
    // cout << d[n];
    // cout << (d[n] % 2 == 1 ? "CY" : "SK");
    cout << ans[d[n]];
}
