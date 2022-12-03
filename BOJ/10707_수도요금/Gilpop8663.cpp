#include <bits/stdc++.h>
using namespace std;

int X, Y, C, D, P;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> X >> Y >> C >> D >> P;

    int xAns = X * P;
    int yAns = Y;

    if (P > C)
    {
        yAns += (P - C) * D;
    }

    int ans = min(xAns, yAns);

    cout << ans;
}
