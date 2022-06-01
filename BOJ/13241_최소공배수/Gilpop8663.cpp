#include <bits/stdc++.h>
using namespace std;

long long int a, b;

int GCD(long long int a, long long int b)
{
    int tmp;
    while (b)
    {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;

    long long int num = a * b / GCD(a, b);

    cout << num;
}
