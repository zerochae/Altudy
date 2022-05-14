#include <bits/stdc++.h>
using namespace std;

int n;

int mod = 15746;

int d[1000005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    d[1] = 1; // 1
    d[2] = 2; // 11 , 00
    d[3] = 3; // 100 111 001
    d[4] = 5;
    for (int i = 4; i <= n; i++)
    {
        d[i] = (d[i - 1] + d[i - 2]) % mod;
    }
    cout << d[n];
}
