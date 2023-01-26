#include <bits/stdc++.h>
using namespace std;

int n, m;

pair<int, int> arr[1005];

vector<int> p(1005, -1);

vector<tuple<long long, int, int>> edge;

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

long long calculateDist(int a, int b)
{
    auto one = arr[a];
    auto two = arr[b];

    int x = one.first - two.first;
    int y = one.second - two.second;

    long long cost = ((long long)x) * x + ((long long)y) * y;
    return cost;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;

        arr[i] = {x, y};
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            long long cost = calculateDist(i, j);

            // int dx = arr[i].first - arr[j].second;
            // int dy = arr[i].second - arr[j].second;

            // long long cost = (long long)dx * dx + (long long)dy * dy;
            edge.push_back({cost, i, j});
        }
    }

    int cnt = 0;
    double ans = 0;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        if (is_diff_group(a, b))
        {
            cnt += 1;
        }
    }

    sort(edge.begin(), edge.end());

    long long cost;

    for (int i = 0; i < edge.size(); i++)
    {

        int a, b;
        tie(cost, a, b) = edge[i];

        if (!is_diff_group(a, b))
            continue;

        ans += sqrt(cost);
        cnt += 1;

        if (cnt == n - 1)
            break;
    }

    cout << fixed;

    cout.precision(2);

    cout << ans;
}

// 1_000_000_000_000
