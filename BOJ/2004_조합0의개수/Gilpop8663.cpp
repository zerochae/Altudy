#include <bits/stdc++.h>
using namespace std;

int n, m;

long long func(int n, int x)
{
    int num = 0;

    for (long long i = x; n / i >= 1; i *= x)
    {
        num += n / i;
    }
    return num;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    long long tN = 0;
    long long fN = 0;

    tN = func(n, 2) - func(n - m, 2) - func(m, 2);
    fN = func(n, 5) - func(n - m, 5) - func(m, 5);

    // cout << fN << " " << tN << "\n";

    long long ans = min(tN, fN);

    cout << ans;

    // n! /(#pragma endregion (n-r) ! * r!);
}
