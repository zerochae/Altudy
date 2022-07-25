#include <bits/stdc++.h>
using namespace std;

int n;

int d[35];

int idx = 0;

void func(int k)
{

    if (k == 1)
    {
        if (idx + 1 == n)
        {
            cout << "m";
            exit(0);
        }
        else if (idx + 2 == n || idx + 3 == n)
        {
            cout << "o";
            exit(0);
        }
        idx += 3;
        return;
    }

    func(k - 1);

    if (idx + 1 == n)
    {
        cout << "m";
        exit(0);
    }

    idx++;

    for (int i = 0; i <= k; i++)
    {
        if (idx + 1 == n)
        {
            cout << "o";
            exit(0);
        }
        idx++;
    }

    func(k - 1);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    func(30);
    // cout << str[n - 1];
}
