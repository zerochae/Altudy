#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[10005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int sum = 0, cnt = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        sum = arr[i];
        if (sum == m)
        {
            cnt++;
            continue;
        }
        for (int j = i + 1; j < n; j++)
        {
            sum += arr[j];

            // cout << sum << " ";
            if (sum > m)
                break;
            if (sum == m)
            {
                cnt++;
                break;
            }
        }
        // cout << "\n";
    }

    cout << cnt;
}
