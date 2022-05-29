#include <bits/stdc++.h>
using namespace std;

int n;

int arr[1005];

vector<int> uni;

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

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            uni.push_back(arr[i] + arr[j]);
        }
    }

    sort(uni.begin(), uni.end());
    // uni.erase(unique(uni.begin(), uni.end()), uni.end());

    // int ans = 0;

    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (binary_search(uni.begin(), uni.end(), arr[i] - arr[j]))
            {
                cout << arr[i];
                return 0;
                // ans = max(ans, arr[i]);
            }

            // cout << arr[i] - arr[j] << " ";
        }
    }

    // cout << ans;
}
