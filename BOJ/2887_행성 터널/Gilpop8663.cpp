#include <bits/stdc++.h>
using namespace std;

int n;

#define ll long long

vector<tuple<int, int, int>> edge;

vector<pair<int, int>> xCost;
vector<pair<int, int>> yCost;
vector<pair<int, int>> zCost;

vector<int> p(100005, -1);

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

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        xCost.push_back({x, i});
        yCost.push_back({y, i});
        zCost.push_back({z, i});
    }

    sort(xCost.begin(), xCost.end());
    sort(yCost.begin(), yCost.end());
    sort(zCost.begin(), zCost.end());

    for (int i = 0; i < n - 1; i++)
    {
        int cost = abs(xCost[i + 1].first - xCost[i].first);
        edge.push_back({cost, xCost[i].second, xCost[i + 1].second});
    }

    for (int i = 0; i < n - 1; i++)
    {
        int cost = abs(yCost[i + 1].first - yCost[i].first);
        edge.push_back({cost, yCost[i].second, yCost[i + 1].second});
    }

    for (int i = 0; i < n - 1; i++)
    {
        int cost = abs(zCost[i + 1].first - zCost[i].first);
        edge.push_back({cost, zCost[i].second, zCost[i + 1].second});
    }

    sort(edge.begin(), edge.end());

    int ans = 0;
    int cnt = 0;

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

// 1_000_000_000
