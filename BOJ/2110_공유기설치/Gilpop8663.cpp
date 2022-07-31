#include <bits/stdc++.h>
using namespace std;

int n, m;

#define X first
#define Y second

const int INF = 1e9 + 10;

int arr[200005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    int low = 0;
    int high = 1e9;

    int ans = 0;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        int start = arr[0];
        int cnt = 1; // 첫번째 공유기는 설치하고 시작
        for (int i = 1; i < n; i++)
        {
            if (arr[i] - start >= mid)
            {
                start = arr[i];
                cnt++;
            }
        }

        if (cnt >= m)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << ans << "\n";

    // cout << low << " " << high << "\n";
}
