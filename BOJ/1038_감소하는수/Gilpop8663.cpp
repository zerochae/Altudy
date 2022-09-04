#include <bits/stdc++.h>
using namespace std;

int n;
long long d[10000010];

queue<long long> q;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i <= 9; i++)
    {
        q.push(i);
        d[i] = i;
    }

    int idx = 10;

    while (idx <= n && !q.empty())
    {
        long long num = q.front();
        q.pop();

        int last = num % 10;
        for (int i = 0; i < last; i++)
        {
            q.push(num * 10 + i);
            d[idx++] = num * 10 + i;
        }
    }

    if (n == 0)
    {
        cout << 0;
        return 0;
    }

    if (idx >= n && d[n] != 0)
        cout << d[n];
    else
        cout << -1;
}
