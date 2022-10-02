#include <bits/stdc++.h>
using namespace std;

int n, t;

bool ch[105] = {1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while (t--)
    {
        fill(ch, ch + 105, 1);
        cin >> n;

        for (int i = 1; i <= n; i++)
        {
            for (int j = i; j <= n; j += i)
            {
                if (ch[j] == 1)
                {
                    ch[j] = 0;
                }
                else
                {
                    ch[j] = 1;
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (ch[i] == 0)
            {
                ans++;
            }
        }

        cout << ans << "\n";
    }
}
