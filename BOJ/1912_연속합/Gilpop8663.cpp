#include <bits/stdc++.h>
using namespace std;

int n;

int d[100005];
int arr[100005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    d[0] = arr[0];

    // d[1] = max(d[0],0) + arr[1];
    // d[2] = max(d[1],0) + arr[2];
    // ...
    // d[n] = max(d[n-1],0) + arr[n];

    for (int i = 1; i < n; i++)
    {
        d[i] = max(d[i - 1], 0) + arr[i];
    }

    cout << *max_element(d, d + n);
}