#include <bits/stdc++.h>

using namespace std;

int n;

long long d[120];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    d[1] = 1;
    d[2] = 1;
    d[3] = 1;

    for (int i = 4; i <= n; i++)
    {
        d[i] = d[i - 1] + d[i - 3];
    }
    cout << d[n];
}