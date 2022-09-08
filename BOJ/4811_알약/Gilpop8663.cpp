#include <bits/stdc++.h>
using namespace std;

int t, n;

long long d[65][65];

long long func(int one, int half)
{

    if (!one)
        return 1;

    long long &ret = d[one][half];

    if (ret != -1)
        return ret;

    ret = 0;

    if (one > 0)
    {
        ret += func(one - 1, half + 1);
    }

    if (half > 0)
    {
        ret += func(one, half - 1);
    }

    return ret;
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(&d[0][0], &d[64][65], -1);
    while (cin >> n)

    {
        if (n == 0)
        {
            break;
        }

        cout << func(n - 1, 1) << "\n";
    }
}
