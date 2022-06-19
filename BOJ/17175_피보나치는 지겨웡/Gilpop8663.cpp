#include <bits/stdc++.h>
using namespace std;

int n;

int d[55];

int mod = 1000000007;

int cnt = 0;

int fibonacci(int n)
{ // 호출

    cnt++;
    if (n < 2)
    {
        return n;
    }
    return fibonacci(n - 2) + fibonacci(n - 1);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    d[0] = 1;
    d[1] = 1;
    d[2] = 3;
    d[3] = 5;
    d[4] = 9;
    d[5] = 15;
    d[6] = 25;
    d[7] = 41;

    for (int i = 2; i <= n; i++)
    {

        d[i] = (d[i - 2] + d[i - 1] + 1) % mod;
    }

    cout << d[n] << "\n";
}
