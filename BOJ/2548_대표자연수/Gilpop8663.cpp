#include <bits/stdc++.h>
using namespace std;

int n;

int arr[20005];

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

    cout << arr[(n - 1) / 2];
}
