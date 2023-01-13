#include <bits/stdc++.h>
using namespace std;

int n, m;

int d[1050000];

void func(int num, int k)
{
    if (num > n)
        return;

    d[num] = k;
    func(num * 2, k);
    func(num * 2 + 1, k);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;

        if (d[num] == 0)
        {
            func(num, num);
            cout << "0"
                 << "\n";
        }
        else
        {
            cout << d[num] << "\n";
        }
    }
}

/*

2,
4 5
8 9 10 11
16 17 18 19 20 21 22 23

16

32 33

64 65

*/
