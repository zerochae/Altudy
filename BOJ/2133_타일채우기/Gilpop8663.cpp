#include <bits/stdc++.h>
using namespace std;

int n;
// 2000000000
int d[35];

int arr[35];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    d[0] = 1;
    d[2] = 3;

    for (int i = 3; i <= n; i++)
    {
        d[i] += (d[i - 2] * 3);

        for (int j = i - 4; j >= 0; j -= 2)
        {
            d[i] += d[j] * 2;
        }
    }

    cout << d[n];
}
