#include <bits/stdc++.h>
using namespace std;

int n, m;

#define X first
#define Y second

const int INF = 1e9 + 10;

int d[1005];

vector<pair<int, int>> arr[1005]; // 비용과 정점

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int start,
    endd;

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
    cin >> start >> endd;

    fill(d, d + 1003, INF);

    d[start] = 0;
    pq.push({d[start], start});

    while (!pq.empty())
    {
        pair<int, int> cur = pq.top();

        pq.pop();

        if (d[cur.Y] != cur.X)
            continue;
        for (auto nxt : arr[cur.Y])
        {
            if (d[nxt.Y] <= d[cur.Y] + nxt.X)
                continue;
            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push({d[nxt.Y], nxt.Y});
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << d[i] << " ";
    // }

    cout << d[endd];
}
