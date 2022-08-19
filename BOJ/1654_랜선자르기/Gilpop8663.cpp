#include <bits/stdc++.h>
using namespace std;

// typedef long long ll;

using ll = long long;

int n, k;

int arr[10005];

vector<int> uni;

bool solve(ll x)
{
    ll cur = 0;
    for (int i = 0; i < n; i++)
    {
        cur += arr[i] / x;
    }
    return cur >= k;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    ll st = 1;
    ll en = 0x7fffffff; // 2^31 -1
    while (st < en)
    {
        ll mid = (st + en + 1) / 2;
        if (solve(mid))
            st = mid;
        else
            en = mid - 1;
    }
    cout << st;
}
