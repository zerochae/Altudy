#include <bits/stdc++.h>
using namespace std;

void moved(int a, int b, int n)
{
    if (n == 1)
    {
        cout << a << " " << b << "\n";
        return;
    }
    moved(a, 6 - a - b, n - 1);
    cout << a << " " << b << "\n";
    moved(6 - a - b, b, n - 1);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    long long count;
    cin >> n;
    count = pow(2, n);

    // cout << (1 << n) - 1 << "\n";
    cout << count - 1 << "\n";
    moved(1, 3, n);
    // cout << ::count << "\n";
}
