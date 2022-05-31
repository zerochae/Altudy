#include <bits/stdc++.h>
using namespace std;

int n;

int arr[105];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = 0;

    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] >= arr[i + 1])
        {

            while (arr[i] >= arr[i + 1])
            {
                arr[i]--;
                ans++;
            }
        }
    }

    cout << ans;
}