#include <bits/stdc++.h>
using namespace std;

long long s, k;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s >> k;

    long long num = (s / k);

    long long ans = 1;

    long long c = s % k;
    for (int i = 0; i < k - c; i++)
    {
        ans *= num;
    }
    for (int i = 0; i < c; i++)
    {
        ans *= num + 1;
    }

    cout << ans;
}
