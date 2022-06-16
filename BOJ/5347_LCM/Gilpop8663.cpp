#include <bits/stdc++.h>
using namespace std;

int n;

long long gcd(long long a, long long b)
{
    long long c;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

long long lcm(long long a, long long b)
{
    return a * b / gcd(a, b);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int num1, num2;
        cin >> num1 >> num2;
        cout << lcm(num1, num2) << "\n";
    }
    // long long num = 999999 * 99999;
    // cout << num;
}