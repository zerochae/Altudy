#include <bits/stdc++.h>
using namespace std;

long long fibo[100];
int n;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    fibo[0] = 0;
    fibo[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }
    cout << fibo[n];
}
