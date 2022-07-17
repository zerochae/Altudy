#include <bits/stdc++.h>
using namespace std;

int n, w, l;

int arr[1005];

queue<int> q;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> w >> l;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = 0;

    int sum = 0;

    for (int i = 0; i < n; i++)
    {

        while (1)
        {
            if (q.size() == w)
            {
                sum -= q.front();
                q.pop();
            }
            if (sum + arr[i] <= l)
                break;
            q.push(0);
            ans++;
        }

        q.push(arr[i]);
        sum += arr[i];
        ans++;
    }

    cout << ans + w;
}
