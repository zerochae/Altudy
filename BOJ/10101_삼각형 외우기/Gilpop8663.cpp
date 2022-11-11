#include <bits/stdc++.h>
using namespace std;

int n, m, k;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;

    if (n == 60 && m == 60 && k == 60)
    {
        cout << "Equilateral";
        return 0;
    }

    if (n + m + k != 180)
    {
        cout << "Error";
        return 0;
    }

    if (n == m || m == k || k == n)
    {
        cout << "Isosceles";
        return 0;
    }

    cout << "Scalene";
    return 0;
}
