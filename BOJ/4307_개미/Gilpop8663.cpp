#include <bits/stdc++.h>
using namespace std;

int t, n, l;

int arr[100005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while (t--)
    {

        cin >> l >> n;

        int maxAns = 0;
        int minAns = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        for (int i = 0; i < n; i++)
        {
            int maxNum = max(arr[i], l - arr[i]);
            int minNum = min(arr[i], l - arr[i]);

            maxAns = max(maxAns, maxNum);
            minAns = max(minAns, minNum);
        }

        cout << minAns << " " << maxAns << "\n";
    }
}
