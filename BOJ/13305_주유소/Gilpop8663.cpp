#include <bits/stdc++.h>
using namespace std;

int n;

long long arr[500005];

int m;
long long arr2[500005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    long long ans = 0;

    for (int i = 0; i < n - 1; i++)
    {
        cin >> arr[i];
    }

    long long price = 1000000010;

    for (int i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }

    for (int i = 0; i < n - 1; i++)
    {

        if (arr2[i] < price)
        {
            price = arr2[i];
        }

        ans += price * arr[i];
    }

    cout << ans;
}
