#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

typedef long long ll;

int n, m;

int d[805]; // 최단 거리 테이블
vector<pair<int, int>> adj[805];

const int INF = 1e9 + 10;

ll func(int st, int en)
{

    fill(d + 1, d + n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    d[st] = 0;

    // 우선순위 큐에 (0,시작점) 추가
    pq.push({d[st], st});

    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        if (d[cur.Y] != cur.X)
            continue;
        for (auto nxt : adj[cur.Y])
        {
            if (d[nxt.Y] <= d[cur.Y] + nxt.X)
                continue;
            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push({d[nxt.Y], nxt.Y});
        }
    }

    // cout << "\n";
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << d[i] << "\n";
    // }
    // cout << "\n";

    return d[en];
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    int st, en;

    cin >> st >> en;

    ll ans1 = func(1, st) + func(st, en) + func(en, n);
    ll ans2 = func(1, en) + func(en, st) + func(st, n);
    ll ans = min(ans1, ans2);

    if (ans >= INF)
    {
        cout << -1;
    }
    else
    {
        cout << ans;
    }
}
