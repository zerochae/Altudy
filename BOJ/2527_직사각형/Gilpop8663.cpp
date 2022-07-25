#include <bits/stdc++.h>
using namespace std;

int n;

char arr[10];

int func(int a, int b, int c, int d)
{
    if (b == c || a == d)
        return 1;
    else if (b < c || d < a)
        return 0;
    else
        return 2;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 4;
    while (n--)
    {

        int lx, ly, rx, ry;

        int lx2, ly2, rx2, ry2;
        cin >> lx >> ly >> rx >> ry >> lx2 >> ly2 >> rx2 >> ry2;

        int ans = func(lx, rx, lx2, rx2) * func(ly, ry, ly2, ry2);
        // cout << ans << "\n";

        if (ans == 0)
        {
            cout << 'd';
        }
        else if (ans == 1)
        {
            cout << 'c';
        }
        else if (ans == 2)
        {
            cout << 'b';
        }
        else
        {
            cout << 'a';
        }
        cout << "\n";
    }
}
