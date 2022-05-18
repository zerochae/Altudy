#include <bits/stdc++.h>
using namespace std;

int n;

int d[50];

int p[50];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    d[0] = 0;
    d[1] = 1;

    p[0] = 1;
    p[1] = 0;
    // d[2] = 1; d[0] d[1]
    // d[3] = 2; d[2] d[1]

    // p[2] = 1;

    for (int i = 2; i <= 40; i++)
    {
        d[i] = d[i - 1] + d[i - 2];
        p[i] += p[i - 1] + p[i - 2];
    }
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        cout << p[num] << " " << d[num] << "\n";
    }
}
