#include <bits/stdc++.h>
using namespace std;

int n;

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

    sort(arr, arr + n);

    int number = n / 3;

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    int num = n - 3;
    for (int i = 0; i < number; i++)
    {
        sum -= arr[num];
        num -= 3;
    }

    cout << sum;
}
