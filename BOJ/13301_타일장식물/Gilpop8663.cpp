#include <bits/stdc++.h>
using namespace std;

int n;

long long d[85];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    d[0] = 1;
    d[1] = 1;
    for (int i = 2; i < n; i++)
    {
        d[i] = d[i - 1] + d[i - 2];
    }
    long long num = d[n - 1] * 2 + (d[n - 2] + d[n - 1]) * 2;
    cout << num;
}
