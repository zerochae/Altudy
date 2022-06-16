#include <bits/stdc++.h>
using namespace std;

int n, k;

int arr[500005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    long long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n + 1);

    for (int i = 1; i <= n; i++)
    {
        sum += abs(arr[i] - i);
    }

    cout << sum;
}
