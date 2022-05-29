#include <bits/stdc++.h>
using namespace std;

int t;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;

        int arr[55];

        for (int j = 0; j < n; j++)
        {
            cin >> arr[j];
        }
        sort(arr, arr + n);

        int maxNum = 0;
        for (int j = 1; j < n; j++)
        {

            if (maxNum < arr[j] - arr[j - 1])
            {
                maxNum = arr[j] - arr[j - 1];
            }
        }
        cout << "Class " << i + 1 << "\n";
        cout << "Max " << arr[n - 1] << ", Min " << arr[0] << ", Largest gap " << maxNum << "\n";
    }
}
