#include <bits/stdc++.h>
using namespace std;

int n;

pair<int, int> arr[10005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int time, m;
        cin >> time >> m;

        int maxNum;
        int minNum;
        if (m == 0)
        {
            maxNum = 0;
            minNum = 0;
        }
        else
        {
            minNum = 1e9;
            maxNum = 0;
        }
        for (int j = 0; j < m; j++)
        {
            int num;
            cin >> num;
            maxNum = max(arr[num].second, maxNum);
            minNum = max(arr[num].second, minNum);
        }

        arr[i].first = maxNum;

        arr[i].second = maxNum + time;

        // cout << arr[i].first << " " << arr[i].second << "\n";
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, arr[i].second);
    }

    cout << ans;

    return 0;
}
