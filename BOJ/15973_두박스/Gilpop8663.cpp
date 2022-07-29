#include <bits/stdc++.h>
using namespace std;

int Qx1, Qx2, Qy1, Qy2;

int Sx1, Sx2, Sy1, Sy2;

int func(int a, int b, int c, int d)
{
    if (b == c || a == d) // 포인트 혹은 라인 구별법
        return 1;

    if (b < c || d < a)
        return 0;

    return 2;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> Qx1 >> Qy1 >> Qx2 >> Qy2;

    cin >> Sx1 >> Sy1 >> Sx2 >> Sy2;

    // cout << func(Qx1, Qx2, Sx1, Sx2) << " " << func(Qy1, Qy2, Sy1, Sy2) << "\n";
    int ans = func(Qx1, Qx2, Sx1, Sx2) * func(Qy1, Qy2, Sy1, Sy2);

    // cout << ans;

    if (ans == 1)
    {
        cout << "POINT";
    }
    else if (ans == 0)
    {
        cout << "NULL";
    }
    else if (ans == 2)
    {
        cout << "LINE";
    }
    else
    {
        cout << "FACE";
    }
}
