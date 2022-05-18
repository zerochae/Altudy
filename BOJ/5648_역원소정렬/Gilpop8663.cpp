#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int n;

ll arr[1000005];

ll rev(ll n)
{
    ll r = 0;
    while (n != 0)
    {
        r *= 10;
        r += n % 10;
        n /= 10;
    }
    return r;
}

int main(void)
{
    cin >> n;

    // cout << n;
    for (int i = 0; i < n; i++)
    {
        ll num;
        cin >> num;
        // cout << num << " ";
        //     // 13
        num = rev(num);
        // cout << num << "\n";
        arr[i] = num;
    }

    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\n";
    }
    // cout << n;
}
