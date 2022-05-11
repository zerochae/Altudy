#include <bits/stdc++.h>
using namespace std;

int n;

long long d[105];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    d[0] = 1;
    d[1] = 1;
    d[2] = 1;
    d[3] = 2;
    d[4] = 2;
    d[5] = 3;
    d[6] = 4;
    d[7] = 5;
    for (int i = 3; i <= 100; i++)
    {
        d[i] = d[i - 3] + d[i - 2];
    }

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        cout << d[num - 1] << "\n";
    }
}
