#include <bits/stdc++.h>
using namespace std;

long long n, m;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    long long ans = abs(n - m);
    cout << ans;
}
