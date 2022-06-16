#include <bits/stdc++.h>
using namespace std;

int t, n, k;

bool arr[20005];

bool ch[20005];

string str;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n;

        for (int i = 2; i <= n; i++)
        {
            int cnt = 0;
            while (true)
            {

                if (n % i != 0)
                    break;
                if (n % i == 0)
                {
                    n /= i;
                    cnt++;
                }
            }
            if (cnt > 0)
            {

                cout << i << " " << cnt << "\n";
            }
        }
    }
}
