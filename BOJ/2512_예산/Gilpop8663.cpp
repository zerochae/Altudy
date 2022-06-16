#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[10005];

bool ch[10005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    sort(arr, arr + n);

    cin >> m;

    int high = 1000000000;
    int low = 0;

    int ans = 0;

    if (sum <= m)
    {
        cout << *max_element(arr, arr + n);
    }
    else
    {

        while (low <= high)
        {
            int mid = (low + high) / 2;
            int total = 0;

            for (int i = 0; i < n; i++)
            {

                if (mid >= arr[i])
                {
                    total += arr[i];
                }
                else
                {
                    total += mid;
                }
            }

            if (total > m)
            {
                high = mid - 1;
            }
            else
            {
                ans = max(ans, mid);
                low = mid + 1;
            }

            // cout << mid << " " << low << " " << high << "\n";
        }

        cout << ans;
    }
}

/*
반례

4
1 5 6 100
18

*/