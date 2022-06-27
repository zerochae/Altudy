#include <bits/stdc++.h>
using namespace std;

int a, b, c;

int d[12];

int memo[25][25][25];

int func(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
    {
        return 1;
    }

    if (a > 20 || b > 20 || c > 20)
    {
        if (memo[20][20][20] > 0)
        {
            return memo[20][20][20];
        }
        memo[20][20][20] = func(20, 20, 20);
        return memo[20][20][20];
    }

    if (a < b && b < c)
    {
        if (memo[a][b][c] > 1)
        {
            return memo[a][b][c];
        }
        memo[a][b][c] = func(a, b, c - 1) + func(a, b - 1, c - 1) - func(a, b - 1, c);
        return memo[a][b][c];
    }

    if (memo[a][b][c] > 1)
    {
        return memo[a][b][c];
    }
    memo[a][b][c] = func(a - 1, b, c) + func(a - 1, b - 1, c) + func(a - 1, b, c - 1) - func(a - 1, b - 1, c - 1);
    return memo[a][b][c];
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < 21; j++)
        {
            for (int k = 0; k < 21; k++)
            {
                func(i, j, k);
            }
        }
    }

    while (cin >> a >> b >> c)
    {
        if (a == -1 && b == -1 && c == -1)
        {
            break;
        }
        cout << "w(" << a << ", " << b << ", " << c << ") = ";
        cout << func(a, b, c) << "\n";
    }
}