#include <bits/stdc++.h>
using namespace std;

int t;
int n;
int m;

int arr[10005];

long long d[10005];

/*
1
10
100 101 102 103 104 105 106 107 108 109
10000
*/

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--)
    {
        fill(d, d + 10005, 0);
        cin >> n;

        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }

        cin >> m;
        d[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            int cnt = 0;
            for (int j = arr[i]; j <= m; j++)
            {
                d[j] = d[j] + d[j - arr[i]];
            }
        }
        cout << d[m] << "\n";
    }
}
