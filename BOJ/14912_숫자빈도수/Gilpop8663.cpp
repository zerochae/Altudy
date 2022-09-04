#include <bits/stdc++.h>
using namespace std;

int n, d;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> d;

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {

        string str = to_string(i);

        for (int j = 0; j < str.size(); j++)
        {
            if (str[j] - '0' == d)
            {
                ans++;
            }
        }
    }

    cout << ans;
}
