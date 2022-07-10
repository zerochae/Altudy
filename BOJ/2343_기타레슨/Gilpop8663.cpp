#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[100005];

int count(int k)
{

    int tmp = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (tmp + arr[i] > k)
        {
            tmp = 0;
            cnt++;
        }
        tmp += arr[i];
    }

    if (tmp != 0)
        cnt++;

    return cnt;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int ans = 0;

    int low = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        low = max(low, arr[i]);
    }

    // sort(arr, arr + n);

    int high = 1e9;

    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;

        // cout << high << " " << low << " " << mid << " " << count(mid) << "\n";

        if (count(mid) <= m)
        {
            high = mid - 1;
            // ans = mid;
        }
        else
        {
            low = mid + 1;
        }
    }

    // count(500);

    ans = low;
    cout << ans;
}