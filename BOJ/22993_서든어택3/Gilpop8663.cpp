#include <bits/stdc++.h>
using namespace std;

int n;

long long me;

long long arr[100005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    cin >> me;

    for (int i = 0; i < n - 1; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n - 1);

    for (int i = 0; i < n - 1; i++)
    {
        // cout << me << " " << arr[i] << "\n";
        if (me > arr[i])
        {
            me += arr[i];
        }
        else
        {
            cout << "No";
            return 0;
        }

        if (me > 1000000000)
        {
            cout << "Yes";
            return 0;
        }
    }

    cout << "Yes";
}
