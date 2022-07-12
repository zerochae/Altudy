#include <bits/stdc++.h>
using namespace std;

int n, t;

int arr[10005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while (t--)
    {
        int ans = 0;
        int tmp[10005];
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            arr[i] = num;
        }

        sort(arr, arr + n);

        int idx1 = 0;
        for (int i = 0; i < n; i += 2)
        {
            tmp[idx1++] = arr[i];
        }

        int idx = n - 1;
        for (int i = 1; i < n; i += 2)
        {

            tmp[idx--] = arr[i];
        }

        for (int i = 0; i < n - 1; i++)
        {
            // cout << tmp[i] << " ";
            ans = max(ans, abs(tmp[i] - tmp[i + 1]));
        }

        ans = max(ans, abs(tmp[0] - tmp[n - 1]));

        cout << ans;
        cout << "\n";
    }
}
