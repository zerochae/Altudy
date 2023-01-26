#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[100005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = 100005;
    int sum = arr[0];
    int idx = 0;
    int idx2 = 0;

    while (true)
    {
        if (idx2 == n)
        {
            break;
        }
        if (sum < m)
        {
            idx2 += 1;
            sum += arr[idx2];
        }
        else
        {
            if (idx == idx2)
            {
                cout << 1;
                return 0;
            }

            ans = min(ans, idx2 - idx + 1);
            sum -= arr[idx];
            idx += 1;
        }
    }

    if (ans == 100005)
    {
        cout << 0;
    }
    else
    {
        cout << ans;
    }
}
