#include <bits/stdc++.h>
using namespace std;

int t, n;

int arr[1005];
int d[1005];



int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        d[0] = arr[0];
        for (int i = 1; i < n; i++)
        {
            d[i] = max(d[i - 1] + arr[i], arr[i]);
            // cout << d[i] << " ";
        }
        // cout << "\n";

        cout << *max_element(d, d + n) << "\n";
    }

    // cout << n << "\n";

    return 0;
}