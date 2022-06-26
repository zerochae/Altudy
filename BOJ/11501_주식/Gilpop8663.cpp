#include <bits/stdc++.h>
using namespace std;

int t, n;

int arr[1000005];

string str;

unordered_set<string> s;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while (t--)
    {

        cin >> n;
        long long ans = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            cin >> arr[i];
        }

        int maxNum = 0;

        for (int i = 0; i < n; i++)
        {
            if (maxNum < arr[i])
            {
                maxNum = arr[i];
            }
            else if (maxNum > arr[i])
            {
                ans += maxNum - arr[i];
            }
        }

        cout << ans << "\n";
    }
}
