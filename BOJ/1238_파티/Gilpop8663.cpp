#include <bits/stdc++.h>
using namespace std;

int n, m, k;

vector<pair<int, int>> adj[1005];
const int INF = 1e9 + 10;

int solve(int st, int en)
{
    int d[1005]; // 최단 거리 테이블

    fill(d, d + n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    d[st] = 0;
    pq.push({0, st});

    while (!pq.empty())
    {
        int u, v, w, dw;
        tie(w, u) = pq.top();
        pq.pop();
        if (d[u] != w)
            continue;
        for (auto nxt : adj[u])
        {
            tie(dw, v) = nxt;
            if (dw + w < d[v])
            {
                d[v] = dw + w;
                pq.push({d[v], v});
            }
        }
    }
    return d[en];
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    for (int i = 0; i < m; i++)
    {
        int st, en, cost;
        cin >> st >> en >> cost;

        adj[st].push_back({cost, en});
    }

    int ans = 0;
    for (int st = 1; st <= n; st++)
    {
        ans = max(ans, solve(st, k) + solve(k, st));
    }

    cout << ans;
}
