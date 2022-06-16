#include <bits/stdc++.h>
using namespace std;

int n;

int arr[1000005];

bool comp(int a, int b)
{
    return a > b;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n, comp);

    for (int i = 0; i < n - 2; i++)
    {
        int num = arr[i];

        if (num < arr[i + 1] + arr[i + 2])
        {
            cout << num + arr[i + 1] + arr[i + 2];
            return 0;
        }
    }

    cout << -1;
}