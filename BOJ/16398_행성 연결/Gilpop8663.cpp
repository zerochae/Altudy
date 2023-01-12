#include <bits/stdc++.h>
using namespace std;

int v, e;

vector<int> p(1005, -1);

tuple<int, int, int> edge[1000005];

int find(int x)
{
    if (p[x] < 0)
        return x;
    return p[x] = find(p[x]);
}

bool is_diff_group(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a == b)
        return 0;
    if (p[a] > p[b])
    {
        swap(a, b);
    }

    p[a] += p[b];
    p[b] = a;
    return 1;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v;

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            int cost;
            cin >> cost;
            if (i >= j)
                continue;
            edge[e++] = {cost, i, j};
        }
    }

    sort(edge, edge + e);

    int cnt = 0;
    long long ans = 0;

    for (int i = 0; i < e; i++)
    {
        int cost, a, b;
        tie(cost, a, b) = edge[i];

        if (!is_diff_group(a, b))
            continue;

        ans += cost;
        cnt += 1;

        if (cnt == v - 1)
            break;
    }

    cout << ans;
}
