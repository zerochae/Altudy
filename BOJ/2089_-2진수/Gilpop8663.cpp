#include <bits/stdc++.h>
using namespace std;

int n;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    if (n == 0)
    {
        cout << "0\n";
        return 0;
    }

    string result;
    while (n != 0)
    {
        if (n % -2 == 0)
        {
            result += "0";
            n /= -2;
        }
        else
        {
            result += "1";
            n = (n - 1) / -2;
        }
    }
    reverse(result.begin(), result.end());

    cout << result << '\n';

    return 0;
}