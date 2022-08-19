#include <bits/stdc++.h>
using namespace std;

int n;

int d[1005];

int arr[1005];



int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    // d[1] = arr[1];
    // d[2] = arr[1] * 2 || d[1] + arr[1] || arr[2];
    // d[3] = arr[1] * 3 || d[2] + arr[1] || arr[3];
    // d[4] = arr[1] * 4 || d[3] + arr[3] || arr[4];

    // d[1] = 1;
    // d[2] = 5;
    // d[3] = 6;
    // d[4] = 10;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            d[i] = max(d[i], d[i - j] + arr[j]);
        }
    }
    cout << d[n];
}
