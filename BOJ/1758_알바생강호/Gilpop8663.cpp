#include <bits/stdc++.h>
using namespace std;

int n, m;

long long arr[100005];

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

    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        long long num = arr[i] - i;

        // cout << arr[i] << " " << i << " " << num << "\n";
        if (num > 0)
        {
            sum += num;
        }
    }

    cout << sum;
}
