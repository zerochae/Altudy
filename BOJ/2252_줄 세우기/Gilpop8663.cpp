#include <bits/stdc++.h>
using namespace std;

int n, m;

vector<int> adj[40000];

int deg[40000];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        deg[b] += 1;
    }

    queue<int> q;

    for (int i = 1; i <= n; i++)
    {
        if (deg[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int num = q.front();
        q.pop();

        cout << num << " ";

        for (auto nxt : adj[num])
        {
            deg[nxt] -= 1;
            if (deg[nxt] == 0)
                q.push(nxt);
        }
    }
}
