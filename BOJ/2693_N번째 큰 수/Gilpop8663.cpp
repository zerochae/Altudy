#include <bits/stdc++.h>
using namespace std;

int n;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int arr[1005];
        for (int k = 0; k < 10; k++)
        {
            cin >> arr[k];
        }

        sort(arr, arr + 10);

        cout << arr[7] << "\n";
    }
}
