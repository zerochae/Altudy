#include <bits/stdc++.h>
using namespace std;

vector<int> p(100005, -1);

tuple<int, int, int> edge[1000005];

int n, e;

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

    cin >> n >> e;

    for (int i = 0; i < e; i++)
    {
        int a, b, cost;
        cin >> a >> b >> cost;
        edge[i] = {cost, a, b};
    }

    sort(edge, edge + e);

    int ans = 0;
    int cnt = 0;

    int maxCost = 0;

    for (int i = 0; i < e; i++)
    {
        int a, b, cost;
        tie(cost, a, b) = edge[i];

        if (!is_diff_group(a, b))
            continue;

        ans += cost;
        maxCost = max(maxCost, cost);
        cnt += 1;

        if (cnt == n - 1)
            break;
    }

    ans -= maxCost;

    cout << ans;
}
