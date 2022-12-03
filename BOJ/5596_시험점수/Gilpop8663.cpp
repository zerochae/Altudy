#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c, d;

    int f, e, g, h;
    cin >> a >> b >> c >> d;
    cin >> f >> e >> g >> h;

    int first = a + b + c + d;
    int second = f + e + g + h;
    int ans = max(first, second);
    cout << ans;
}
