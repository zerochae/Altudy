#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[55];
bool ch[55] = {0};

bool comp(int a, int b)
{
    return abs(a) < abs(b);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] < 0)
        {
            cnt++;
        }
    }

    sort(arr, arr + n);

    for (int i = 0; i < cnt; i += m)
    {
        ans += abs(arr[i] * 2);
    }

    for (int i = n - 1; i >= cnt; i -= m)
    {
        ans += abs(arr[i]) * 2;
    }

    ans -= max(abs(arr[0]), arr[n - 1]);

    cout << ans;
}
