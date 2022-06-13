#include <bits/stdc++.h>
using namespace std;

int n;

double a, b;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> a >> b;

    if (n % 2 == 1)
    {
        n++;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        // cout << a << " " << b << "\n";
        if (a == b)
            break;
        cnt++;
        double num1 = ceil(a / 2);
        double num2 = ceil(b / 2);
        a = num1;
        b = num2;
        // cout << num1 << " " << num2 << "\n";
        // b = num2;
    }

    cout << cnt;
}
