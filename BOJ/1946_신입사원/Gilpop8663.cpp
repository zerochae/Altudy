#include <bits/stdc++.h>
using namespace std;

int t, n;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while (t--)
    {
        pair<int, int> arr[100005];

        cin >> n;

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            int num1, num2;

            cin >> num1 >> num2;

            arr[i] = {num1, num2};
        }

        sort(arr, arr + n);

        int minNum = 1000005;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {

            if (minNum > arr[i].second)
            {
                minNum = arr[i].second;
                cnt++;
            }

            if (arr[i].second == 1)
                break;

            // cout << arr[i].first << " " << arr[i].second << "\n";
        }

        ans = cnt;
        cout << ans << "\n";
    }
}
