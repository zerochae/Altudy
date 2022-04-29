#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll n;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    long long maxNum = 0;
    ll minNum = 999999;

    for (ll i = 0; i < n; i++)
    {
        ll num;
        cin >> num;
        // cout << num;
        minNum = min(num, minNum);
        maxNum = max(num, maxNum);
    }

    cout << minNum * maxNum;
}
