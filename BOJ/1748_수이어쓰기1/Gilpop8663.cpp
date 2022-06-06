#include <bits/stdc++.h>
using namespace std;

int n;

int sum = 0;

string str;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i *= 10)
    {
        sum += n - i + 1;
        // cout << sum << "\n";
    }

    cout << sum;
}
