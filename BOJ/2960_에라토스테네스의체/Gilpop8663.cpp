#include <bits/stdc++.h>
using namespace std;

int n, m;

bool num[1005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int cnt = 0;

    for (int i = 2; i <= n; i++)
    {
        num[i] = 1;
    }

    bool flag = 0;
    for (int i = 2; i <= n; i++)
    {
        if (flag == 1)
            break;
        if (num[i] == 0)
            continue;
        for (int j = i; j <= n; j += i)
        {
            if (num[j] == 0)
                continue;
            num[j] = 0;
            cnt++;

            if (cnt == m)
            {
                cout << j << "\n";
                flag = 1;
                break;
            }
            // cout << j << " " << cnt << "\n";
        }
    }
}
