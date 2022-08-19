#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[500005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        cout << upper_bound(arr, arr + n, num) - lower_bound(arr, arr + n, num) << " ";
    }
}
