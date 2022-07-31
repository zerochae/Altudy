#include <bits/stdc++.h>
using namespace std;

int n, m;

#define X first
#define Y second

const int INF = 1e9 + 10;

vector<pair<int, int>> arr[1005]; // {비용 , 정점}
int d[1005];
int pre[1005];

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int st, en, cost;
        cin >> st >> en >> cost;
        arr[st].push_back({cost, en});
    }

    fill(d, d + 1003, INF);

    int start, end;
    cin >> start >> end;
    d[start] = 0;
    pq.push({d[start], start});

    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();

        if (d[cur.Y] != cur.X)
            continue;

        for (auto nxt : arr[cur.Y])
        {
            if (d[nxt.Y] <= d[cur.Y] + nxt.X)
                continue;
            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push({d[nxt.Y], nxt.Y});
            pre[nxt.Y] = cur.Y;
        }
    }

    cout << d[end] << "\n";

    vector<int> path;

    int cur = end;

    while (cur != start)
    {
        path.push_back(cur);
        cur = pre[cur];
    }
    path.push_back(cur);

    reverse(path.begin(), path.end());

    cout << path.size() << "\n";

    for (auto x : path)
    {
        cout << x << " ";
    }
}
