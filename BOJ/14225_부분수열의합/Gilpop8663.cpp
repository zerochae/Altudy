#include <bits/stdc++.h>
using namespace std;

int n;

int arr[22];

bool d[2000005];

set<int> s;

void func(int k, int sum)
{

    if (k == n)
    {
        s.insert(sum);
        return;
    }

    func(k + 1, sum + arr[k]);
    func(k + 1, sum);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    func(0, 0);

    int cnt = 0;
    for (auto x : s)
    {
        // cout << x << " ";
        d[x] = 1;
    }

    for (int i = 1; i <= 2000000; i++)
    {
        if (d[i] == 0)
        {
            cout << i;
            break;
        }
    }
}
