#include <bits/stdc++.h>
using namespace std;

string a, b;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;

    int n = a.size();
    int m = b.size();

    int ans = 99999;

    for (int i = 0; i < max(n, m); i++)
    {
        string str;
        int cnt = 0;
        if (n > m)
        {
            str = a.substr(i);
            for (int j = 0; j < min(n, m); j++)
            {
                if (str[j] != b[j])
                {
                    cnt++;
                }
            }
        }
        else
        {
            str = b.substr(i);
            for (int j = 0; j < min(n, m); j++)
            {
                // cout << str[j] << " " << a[j] << "\n";
                if (str[j] != a[j])
                {
                    cnt++;
                }
            }
        }

        if (str.size() < min(n, m))
            break;

        ans = min(ans, cnt);

        // cout << str << " " << ans << "\n";
    }

    cout << ans;
}
