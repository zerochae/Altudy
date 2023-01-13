#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[305];

int arr2[305][305];

vector<int> p(10005, -1);

tuple<int, int, int> edge[100005];

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
    {

        return 0;
    }
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

    int e = 0;

    for (int i = 0; i < n; i++)
    {
        int cost;
        cin >> cost;
        edge[e++] = {cost, i, n};
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int cost;
            cin >> cost;
            if (i >= j)
                continue;
            edge[e++] = {cost, i, j};
        }
    }

    n += 1; // 가상의 정점

    sort(edge, edge + e);

    int cnt = 0;
    int ans = 0;

    for (int i = 0; i < e; i++)
    {
        int a, b, cost;
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