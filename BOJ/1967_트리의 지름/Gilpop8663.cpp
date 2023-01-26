#include <bits/stdc++.h>
using namespace std;

int n;

bool ch[10005] = {0};
vector<pair<int, int>> edge[10005];

int ans = 0;
int point = 0;

void dfs(int k, int sum)
{
    bool isFlag = false;

    for (int i = 0; i < edge[k].size(); i++)
    {
        auto nxt = edge[k][i];
        int nxtNum = nxt.first;
        int cost = nxt.second;
        if (ch[nxtNum] == 1)
            continue;
        ch[nxtNum] = 1;
        isFlag = true;
        dfs(nxtNum, sum + cost);
    }

    if (!isFlag)
    {
        if (sum > ans)
        {
            ans = sum;
            point = k;
        }
    }
    return;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int u, v, cost;
        cin >> u >> v >> cost;
        edge[u].push_back({v, cost});
        edge[v].push_back({u, cost});
    }
    ch[1] = 1;
    dfs(1, 0);

    // cout << ans << " " << point << "\n";

    fill(ch, ch + n + 1, 0);

    ans = 0;
    ch[point] = 1;
    dfs(point, 0);
    // cout << ans << " " << point;

    cout << ans;
}
