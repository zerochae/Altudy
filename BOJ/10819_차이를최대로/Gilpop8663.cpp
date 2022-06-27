#include <bits/stdc++.h>
using namespace std;

int n;

int arr[10];

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

    int ans = 0;

    do
    {
        int sum = 0;
        for (int i = 0; i < n - 1; i++)
        {
            sum += abs(arr[i] - arr[i + 1]);
        }
        ans = max(ans, sum);
    } while (next_permutation(arr, arr + n));

    cout << ans;
}

/*

6
20 1 15 8 4 10


8 15 1 20 4 10
8 15 4 20 1 10
8 20 1 15 4 10
8 20 4 15 1 10
10 1 15 4 20 8
10 1 20 4 15 8
10 4 15 1 20 8
10 4 20 1 15 8

ans = 62


*/