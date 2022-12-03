#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    cin >> str;

    double ans = 0;
    cout << fixed;
    cout.precision(1);
    if (str[0] == 'A')
        ans = 4.0;
    else if (str[0] == 'B')
        ans = 3.0;
    else if (str[0] == 'C')
        ans = 2.0;
    else if (str[0] == 'D')
        ans = 1.0;
    else if (str[0] == 'F')
    {
        ans = 0;
        cout << ans;
        return 0;
    }

    if (str[1] == '+')
    {
        ans += 0.3;
    }
    else if (str[1] == '-')
    {
        ans -= 0.3;
    }

    cout << ans;
}
