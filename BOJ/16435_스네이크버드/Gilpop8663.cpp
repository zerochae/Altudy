#include <bits/stdc++.h>
using namespace std;

int n, l;

int arr[1005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= l)
        {
            l++;
        }
    }
    cout << l;
}