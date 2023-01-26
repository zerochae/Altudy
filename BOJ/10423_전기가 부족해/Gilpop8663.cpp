#include <bits/stdc++.h>
using namespace std;

int n, m, k;

vector<int> p(1005, -1);

vector<tuple<int, int, int>> edge;

int find(int x)
{
    if (p[x] < 0)
        return x;
    return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v)
{
    u = find(u);
    v = find(v);

    if (u == v)
        return 0;
    if (p[u] > p[v])
    {
        swap(u, v);
    }

    p[u] += p[v];
    p[v] = u;
    return 1;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    n++;

    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;

        edge.push_back({0, x, n});
    }

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edge.push_back({w, u, v});
    }

    sort(edge.begin(), edge.end());

    int cnt = 0;
    int ans = 0;

    for (int i = 0; i < edge.size(); i++)
    {
        int cost, a, b;
        tie(cost, a, b) = edge[i];

        if (!is_diff_group(a, b))
            continue;
        ans += cost;
        cnt += 1;

        if (cnt == n - 1)
            break;
    }

    cout << ans;
}
