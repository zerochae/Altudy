#include <bits/stdc++.h>
using namespace std;

int n, k;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    int tot = n;

    int num;

    if (n <= k)
    {
        cout << 0;
        return 0;
    }
    else
    {

        int ans = 0;

        while (1)
        {
            int cnt = 0;
            int tmp = n;

            while (tmp > 0)
            {
                if (tmp % 2 == 0)
                {
                    tmp /= 2;
                }
                else
                {
                    tmp /= 2;
                    cnt++;
                }
            }

            // cout << n << " " << k << " " << cnt << "\n ";
            if (k >= cnt)
            {
                break;
            }

            n++;
            ans++;
        }

        cout << ans;
    }
}
