#include <bits/stdc++.h>
using namespace std;

int n;

int arr[500005];

stack<pair<int, int>> s;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        int now;

        int sameCnt = 1;
        cin >> now;

        while (!s.empty() && s.top().first < now)
        {
            ans += s.top().second;
            s.pop();
        }

        if (!s.empty())
        {
            if (s.top().first == now)
            {
                ans += s.top().second;
                sameCnt = s.top().second + 1;

                if (s.size() > 1)
                {
                    ans++;
                }

                s.pop();
            }
            else
            {
                ans++;
            }
        }

        s.push({now, sameCnt});
    }

    cout << ans;
}