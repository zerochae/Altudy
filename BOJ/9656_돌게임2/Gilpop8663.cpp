#include <bits/stdc++.h>
using namespace std;

int n;

int d[1005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    d[1] = 0;
    d[2] = 1;
    d[3] = 0;
    int a[] = {1, 3};
    for (int i = 4; i <= n; i++)
    {
        for (int j : a)
        {
            if (d[i - j] == 1)
            {
                d[i] = 0;
                break;
            }
            else
            {
                d[i] = 1;
            }
        }
    }
    // cout << d[n];

    if (d[n] % 2 == 0)
    {
        cout << "CY";
    }
    else
    {
        cout << "SK";
    }
}