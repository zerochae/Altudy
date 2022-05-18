#include <bits/stdc++.h>
using namespace std;

int t;
int n;

int d[1000005];

int mod = 1000000009;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;

    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    d[4] = 7;
    // 1+1+1+1 , 1+2+1 , 2+1+1 , 3+1
    // 1+1+2 , 2+2
    // 1+3
    for (int i = 4; i <= 1000000; i++)
    {
        d[i] = ((d[i - 3] + d[i - 2]) % mod + d[i - 1]) % mod;
    }
    for (int i = 0; i < t; i++)
    {
        int num;
        cin >> num;
        cout << d[num] << "\n";
    }
}
