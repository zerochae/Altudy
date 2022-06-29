#include <bits/stdc++.h>
using namespace std;

int n;

int arr[2005];
int d[2005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    fill(d, d + n, 1);

    for (int i = n - 1; i >= 0; i--)
    {
        cin >> arr[i];
    }

    int ans = 0;

    for (int i = 1; i < n; i++)

    {
        for (int j = 0; j < i; j++)
        {

            if (arr[i] > arr[j])
            {
                d[i] = max(d[i], d[j] + 1);
            }
        }

        // cout << d[i] << " ";
    }

    ans = n - *max_element(d, d + n);

    cout << ans;
}
