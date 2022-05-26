#include <bits/stdc++.h>
using namespace std;

int n, k;

int arr[1005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    int sum = 0;
    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        arr[i] = i;
        sum += i;
    }

    if (n < sum)
    {
        cout << -1;
        return 0;
    }

    n -= sum;

here:
    for (int i = k; i > 0 && n > 0; i--)
    {
        arr[i]++;
        n--;
    }

    if (n > 0)
        goto here;

    ans = arr[k] - arr[1];

    cout << ans;
    // 17 4
    // 11 4 1 2 3 4  = 10   2 3 4 5 = 14  3 4 5 6 = 18
    // 2 3 4 8 = 17  2 3 5 7 = 2 4 5 6
}