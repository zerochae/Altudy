#include <bits/stdc++.h>
using namespace std;

int n;

int a[55];
int b[55];

bool func(int a, int b)
{
    return a > b;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    sort(a, a + n);
    sort(b, b + n, func);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += a[i] * b[i];
    }
    cout << ans;
}
