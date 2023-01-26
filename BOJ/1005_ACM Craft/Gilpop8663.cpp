#include <bits/stdc++.h>
using namespace std;

int t, n, m;

#define X first
#define Y second

int arr[1005];

vector<int> adj[1005];
int deg[1005];

int dp[1005];

int ans = 0;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n >> m;

        fill(deg, deg + n + 1, 0);
        fill(arr, arr + n + 1, 0);
        fill(dp, dp + n + 1, 0);

        for (int i = 0; i <= n; i++)
        {
            adj[i].clear();
        }

        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }

        for (int j = 0; j < m; j++)
        {
            int st, en;
            cin >> st >> en;
            adj[st].push_back(en);
            deg[en] += 1;
        }

        int endPoint;
        cin >> endPoint;

        queue<int> q;

        for (int i = 1; i <= n; i++)
        {
            if (deg[i] == 0)
            {
                q.push(i);
                dp[i] = arr[i];
            }
        }

        while (!q.empty())
        {
            int num = q.front();
            q.pop();

            for (int i = 0; i < adj[num].size(); i++)
            {
                int nxt = adj[num][i];
                dp[nxt] = max(dp[nxt], dp[num] + arr[nxt]);
                deg[nxt]--;
                if (deg[nxt] == 0)
                {
                    q.push(nxt);
                }
            }
        }

        cout << dp[endPoint] << "\n";
    }
}
