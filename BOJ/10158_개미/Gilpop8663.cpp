#include <bits/stdc++.h>
using namespace std;

int n, m, p, q, t;

int dy[] = {1, 1, -1, 1}; // 1,1 -1,1  -1-1 -1 1
int dx[] = {1, -1, -1, -1};

int dir = 0;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    cin >> p >> q;

    cin >> t;

    int x = (p + t) % (2 * n);
    int y = (q + t) % (2 * m);

    if (x > n)
    {
        x = 2 * n - x;
    }
    if (y > m)
    {
        y = 2 * m - y;
    }
    cout << x << " " << y;
}