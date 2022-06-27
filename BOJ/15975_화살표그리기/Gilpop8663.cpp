#include <bits/stdc++.h>
using namespace std;

int n;

pair<long long, long long> arr[100005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int dim, color;

        cin >> dim >> color;

        arr[i] = {color, dim};
    }

    sort(arr, arr + n);

    long long ans = 0;

    for (int i = 0; i < n; i++)
    {
        // cout << arr[i].first << "\n";
        // cout << arr[i].first << " " << arr[i].second << "\n";
        // cout << arr[i + 1].first << " " << arr[i + 1].second << "\n";
        // cout << arr[i + 1].second << " " << arr[i].second << "\n";
        // cout << "\n";
        if (arr[i].first == arr[i + 1].first && arr[i - 1].first == arr[i].first)
        {
            ans += min(abs(arr[i].second - arr[i - 1].second), abs(arr[i + 1].second - arr[i].second));
        }
        else if (arr[i].first == arr[i + 1].first)
        {

            ans += abs(arr[i + 1].second - arr[i].second);

            long long num = abs(arr[i + 1].second - arr[i].second);

            // cout << num << "\n";
        }
        else if (arr[i - 1].first == arr[i].first)
        {
            ans += abs(arr[i].second - arr[i - 1].second);
            long long num = abs(arr[i].second - arr[i - 1].second);
            // cout << num << "\n";
        }
    }

    cout << ans;
}
