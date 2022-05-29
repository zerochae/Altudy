#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll n;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    ll sum = 0;

    int cnt = 0;
    for (int i = 1; sum + i <= n; i++)
    {
        sum += i;
        cnt = i;
    }
    // cout << cnt << " " << sum;
    cout << cnt;
}
