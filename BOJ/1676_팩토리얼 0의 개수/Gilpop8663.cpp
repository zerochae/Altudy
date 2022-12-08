#include <bits/stdc++.h>
using namespace std;

int n;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int mul5 = n / 5;
    int mul25 = n / 25;
    int mul125 = n / 125;

    int ans = mul5 + mul25 + mul125;

    cout << ans;
}
