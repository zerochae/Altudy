#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m;

tuple<int, int, int> edge[1000005];

vector<int> p(1005, -1);

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

    cin >> n >> m;

    m++;

    for (int i = 0; i < m; i++)
    {
        int a, b, cost;
        cin >> a >> b >> cost;
        edge[i] = {cost, a, b};
    }

    sort(edge, edge + m);

    int maxAns = 0;
    int minAns = 0;
    int cnt = 0;

    for (int i = 0; i < m; i++)
    {
        int a, b, cost;
        tie(cost, a, b) = edge[i];

        if (!is_diff_group(a, b))
            continue;

        minAns += cost == 0 ? 1 : 0;
        cnt += 1;

        if (cnt == n)
            break;
    }

    fill(p.begin(), p.end(), -1);

    sort(edge, edge + m, greater<tuple<int, int, int>>());

    cnt = 0;

    for (int i = 0; i < m; i++)
    {
        int a, b, cost;
        tie(cost, a, b) = edge[i];

        if (!is_diff_group(a, b))
            continue;

        maxAns += cost == 0 ? 1 : 0;
        cnt += 1;

        if (cnt == n)
            break;
    }

    int ans = minAns * minAns - maxAns * maxAns;

    cout << ans;
}
