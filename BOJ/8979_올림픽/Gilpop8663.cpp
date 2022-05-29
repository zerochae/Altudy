#include <bits/stdc++.h>
using namespace std;

int n, k;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    int arr[1006][4];

    int ans[1006];

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3];
    }

    // sort(arr + 1, arr + n + 1, comp);

    for (int i = 1; i <= n; i++)
    {
        int cnt = 1;
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            if (arr[j][1] > arr[i][1])
            {
                cnt++;
                continue;
            }
            if (arr[j][1] == arr[i][1])
            {
                if (arr[j][2] > arr[i][2])
                {
                    cnt++;
                    continue;
                }
                if (arr[j][2] == arr[i][2])
                {
                    if (arr[j][3] > arr[i][3])
                    {
                        cnt++;
                        continue;
                    }
                    // if (arr[j][3] == arr[i][3])
                    // {
                    //     cnt++;
                    //     continue;
                    // }
                }
            }
        }
        // cout << arr[i][0] << " " << cnt << "\n";
        ans[arr[i][0]] = cnt;
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << ans[i] << "\n";
    // }
    cout << ans[k];
}
