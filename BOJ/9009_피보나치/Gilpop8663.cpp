#include <bits/stdc++.h>
using namespace std;

int t, n, l;

int d[50];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    d[0] = 1;
    d[1] = 1;
    for (int i = 2; i < 46; i++)
    {
        d[i] = d[i - 1] + d[i - 2];
    }

    // cout << d[45];
    while (t--)
    {
        cin >> n;

        stack<int> s;

        while (1)
        {
            if (n == 0)
                break;
            for (int i = 45; i >= 0; i--)
            {
                if (n >= d[i])
                {
                    n -= d[i];
                    s.push(i);
                }
            }
        }

        while (!s.empty())
        {
            int num = s.top();

            s.pop();
            cout << d[num] << " ";
        }
        cout << "\n";
    }
}
