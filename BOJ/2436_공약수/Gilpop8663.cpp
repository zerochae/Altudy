#include <bits/stdc++.h>
using namespace std;

int n, m;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int resultA, resultB;

    int divide = m / n;

    for (int i = 1; i <= sqrt(divide); i++)
    {
        if (divide % i == 0)
        {
            int a = i;
            int b = divide / i;

            if (gcd(a, b) == 1)
            {
                resultA = a;
                resultB = b;
            }
        }
    }

    cout << resultA * n << " " << resultB * n;
}
