#include <bits/stdc++.h>
using namespace std;

int n;

int d[100005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int cnt = 0;

    d[0] = 0;
    d[1] = -1;
    d[2] = 1;
    d[3] = -1;
    d[4] = 2;
    d[5] = 1;
    d[6] = 3;
    d[7] = 2;
    d[8] = 4;
    d[9] = 3;
    d[10] = 2;
    d[11] = 4;
    d[12] = 3;
    d[13] = 5;
    d[14] = 4;
    d[15] = 3;
    d[16] = 5;
    d[17] = 4;

    for (int i = 10; i <= n; i++)
    {
        d[i] = min(d[i - 2], d[i - 5]) + 1;
    }
    cout << d[n];
}
