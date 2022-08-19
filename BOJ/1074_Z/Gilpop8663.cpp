#include <bits/stdc++.h>
using namespace std;

int func(int n, int r, int c)
{
    if (n == 0)
    {
        return 0;
    }
    long long half = pow(2, n - 1);
    if (half > r && c < half)
        return func(n - 1, r, c);
    if (half > r && c >= half)
        return half * half + func(n - 1, r, c - half);
    if (half <= r && c < half)
        return 2 * half * half + func(n - 1, r - half, c);
    return 3 * half * half + func(n - 1, r - half, c - half);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, r, c;
    cin >> n >> r >> c;
    cout << func(n, r, c);
}
