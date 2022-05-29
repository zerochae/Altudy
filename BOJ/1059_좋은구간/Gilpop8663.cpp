#include <bits/stdc++.h>
using namespace std;

int n, k;

int arr[55];

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

    cin >> k;

    int minNum = 1, maxNum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < k && arr[i + 1] > k)
        {
            minNum = arr[i] + 1;
            maxNum = arr[i + 1] - 1;
        }
    }

    // cout << minNum << " " << maxNum << "\n";

    if (minNum == 1 && arr[0] > k)
    {

        maxNum = arr[0] - 1;
    }

    int cnt = 0;
    for (int i = minNum; i <= k; i++)
    {
        for (int j = k; j <= maxNum; j++)
        {
            if (i == j)
            {
                continue;
            }
            cnt++;
            // cout << i << " " << j << "\n";
        }
    }

    cout << cnt;
}
