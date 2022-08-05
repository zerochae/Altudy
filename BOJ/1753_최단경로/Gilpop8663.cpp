#include <bits/stdc++.h>
using namespace std;

int n, m;

#define X first
#define Y second

const int INF = 1e9 + 10;

int d[20005];

vector<pair<int, int>> arr[20005]; // {비용 , 정점}

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int st;
    cin >> st;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;

        cin >> u >> v >> w;

        arr[u].push_back({w, v});
    }

    fill(d, d + 20003, INF);

    d[st] = 0;
    pq.push({d[st], st});

    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();

        if (d[cur.Y] != cur.X)
            continue; // 현재 값과 d에 저장된 값이 다르면 넘어간다

        for (auto nxt : arr[cur.Y])
        {
            if (d[nxt.Y] <= d[cur.Y] + nxt.X) // 정점까지의 거리가 현재 저장된 값 + 거기까지 가는 값보다 작다면
                continue;
            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push({d[nxt.Y], nxt.Y});
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (d[i] == INF)
        {
            cout << "INF"
                 << "\n";
        }
        else
        {

            cout << d[i] << "\n";
        }
    }
}
