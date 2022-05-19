#include <bits/stdc++.h>
using namespace std;

int n;
// 2000000000
int d[10005];

int arr[10005];

int mod = 1000000;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // cin >> n;
    d[0] = 0;
    d[1] = 0;
    string s;
    cin >> s;

    n = s.size();
    for (int i = 1; i <= n; i++)
    {
        arr[i] = s[i - 1] - '0';
        // cout << arr[i] << " ";
    }

    d[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] > 0)
        {
            d[i] = (d[i] + d[i - 1]) % mod;
        }
        int x = arr[i - 1] * 10 + arr[i];
        if (x >= 10 && x <= 26)
        {
            d[i] = (d[i] + d[i - 2]) % mod;
        }
    }
    cout << d[n];
}
