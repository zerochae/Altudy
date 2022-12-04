#include <bits/stdc++.h>
using namespace std;

int n, t, c, p;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> t >> c >> p;

    int price = c * p;
    int days = (n - 1) / t;
    int ans = price * days;
    cout << ans;
}