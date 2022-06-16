#include <bits/stdc++.h>
using namespace std;

int n;

int d[50050];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int cnt = 0;

    d[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        d[i] = d[1] + d[i - 1];

        for (int j = 2; j * j <= i; j++)
        {
            d[i] = min(d[i], 1 + d[i - j * j]); // d[5] = d[5],d[5-4]+1 d[6-4]+1 d[2-1]+1
        }
    }

    cout << d[n];
}
