#include <bits/stdc++.h>
using namespace std;

int n, k;

int arr[200005] = {-999};
int d[200005] = {-999};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }

    // cout << sum << "\n";
    d[0] = sum;
    for (int i = 1; i <= n - k; i++)
    {
        d[i] = d[i - 1] + arr[i + k - 1] - arr[i - 1];
        // cout << d[i] << " " << arr[i + k - 1] << " " << arr[i - 1] << "\n";
    }

    cout << *max_element(d, d + n - k + 1);
}
