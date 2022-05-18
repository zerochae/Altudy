#include <bits/stdc++.h>
using namespace std;

int n;

int d[1005];

int pre[1005];
int arr[1005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    fill(d, d + n, 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (arr[j] < arr[i] && d[i] < d[j] + 1)
            {
                d[i] = d[j] + 1;
                pre[i] = j;
            }
        }
    }

    int maxi = 1;
    int maxd = d[1];

    for (int i = 2; i <= n; i++)
    {

        if (maxd < d[i])
        {
            maxi = i;
            maxd = d[i];
        }
    }

    // int ans = 0;
    int cur = maxi;
    deque<int> ans;
    while (cur)
    {
        ans.push_front(arr[cur]);
        cur = pre[cur];
        // cout << cur << " " << pre[i] << " " << maxi << "\n";
    }

    cout << ans.size() << "\n"; // d[1] 이 없을수도 있음.
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}
