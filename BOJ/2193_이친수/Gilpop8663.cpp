#include <bits/stdc++.h>
using namespace std;

int n;

long long d[100];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    d[1] = 1; // 1
    d[2] = 1; // 10
    d[3] = 2; // 100,101
    d[4] = 3; // 1000 ,1001, 1010
    for (int i = 3; i <= n; i++)
    {
        d[i] = d[i - 2] + d[i - 1];
    }
    cout << d[n];
}
