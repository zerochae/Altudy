#include <bits/stdc++.h>
using namespace std;

int n;

pair<int, int> arr[105];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int num1, num2;
        cin >> num1 >> num2;

        arr[i] = {num1, num2};
    }

    sort(arr, arr + n);
    int ans = arr[0].first;
    // cout << ans << "\n";
    for (int i = 0; i < n; i++)
    {
        // cout << ans << "\n";
        if (ans < arr[i].first)
        {
            ans = arr[i].first;
        }
        ans += arr[i].second;
    }

    cout << ans;
}