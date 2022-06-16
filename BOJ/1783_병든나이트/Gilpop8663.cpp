#include <bits/stdc++.h>
using namespace std;

int n, m;

int dx[4] = {-1, -2, 1, 2};
int dy[4] = {2, 1, 2, 1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    if (n == 1)
    {
        cout << 1;
    }
    else if (n == 2)
    {
        cout << min(4, (m - 1) / 2 + 1);
    }
    else
    {
        if (m >= 7)
        {
            cout << m - 2;
        }
        else
        {
            cout << min(4, m);
        }
    }
}
