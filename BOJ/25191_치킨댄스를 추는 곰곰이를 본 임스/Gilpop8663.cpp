#include <bits/stdc++.h>
using namespace std;

int n;

int c, b;

map<string, int> arr;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> c >> b;

    int ans = min(n, (c / 2) + b);

    cout << ans;
}
