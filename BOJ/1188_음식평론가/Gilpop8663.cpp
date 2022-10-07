#include <bits/stdc++.h>
using namespace std;

int n, m;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int ans = m - gcd(n, m);

    cout << ans;
}
