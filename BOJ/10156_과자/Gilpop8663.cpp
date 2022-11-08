#include <bits/stdc++.h>
using namespace std;

int n, m, k;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> k >> n >> m;

    int money = k * n;

    if (money > m)
    {
        cout << money - m;
    }
    else
    {
        cout << 0;
    }
}
