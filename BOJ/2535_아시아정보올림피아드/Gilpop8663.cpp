#include <bits/stdc++.h>
using namespace std;

int n;

pair<int, pair<int, int>> arr[105];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int coun, num, score;
        cin >> coun >> num >> score;
        arr[i] = {score, {coun, num}};
    }

    sort(arr, arr + n);

    int prev = 0;
    int cnt = 1;
    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        // cout << arr[i].first << " " << arr[i].second.first << " " << arr[i].second.second << " " << cnt << " " << ans << "\n";
        if (ans >= 3)
        {
            break;
        }
        if (prev == arr[i].second.first)
        {
            cnt++;
            if (cnt > 2)
            {
                continue;
            }

            cout << arr[i].second.first << " " << arr[i].second.second << "\n";
            ans++;
            continue;
        }

        if (arr[i].second.first == arr[i - 1].second.first)
        {
            prev = arr[i].second.first;
            cout << arr[i].second.first << " " << arr[i].second.second << "\n";
            ans++;
            continue;
        }

        cout << arr[i].second.first << " " << arr[i].second.second << "\n";
        ans++;
    }
}
