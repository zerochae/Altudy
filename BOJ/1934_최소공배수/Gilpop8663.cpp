#include <bits/stdc++.h>
using namespace std;

int t;

int gcd(int a, int b)
{
    int r;
    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while (t--)
    {

        int a, b;

        cin >> a >> b;

        cout << (a * b) / gcd(a, b)
             << "\n";
    }
}