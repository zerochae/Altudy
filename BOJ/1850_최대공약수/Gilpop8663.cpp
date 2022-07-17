#include <bits/stdc++.h>
using namespace std;

long long n, m;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    long long ans = gcd(n, m);

    // cout << ans;

    string str;

    for (int i = 0; i < ans; i++)
    {
        str += '1';
    }

    cout << str;
}
