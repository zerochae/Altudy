#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[100005];

bool ch(int mid)
{
    int num = 1;
    int sum = mid;
    for (int i = 0; i < n; i++)
    {
        if (mid < arr[i])
            return false;

        if (sum - arr[i] < 0)
        {
            sum = mid;
            num++;
        }
        sum -= arr[i];
    }
    return m >= num;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int low = 0;
    int high = 1e9;

    int ans = 0;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (ch(mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }

        // cout << mid << " " << low << " " << high << "\n";
    }

    cout << ans;
}
