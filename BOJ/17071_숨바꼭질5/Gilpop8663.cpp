#include <bits/stdc++.h>
using namespace std;

int n, k;

queue<pair<int, int>> q; // 수빈 위치, 동생 위치

int board[1000005];
int vis[2][1000005]; // 걸린 시간..

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    q.push({n, 0});

    fill(&vis[0][0], &vis[1][1000004], -1);

    vis[0][n] = 0;

    while (!q.empty()) // 수빈이의 이동 BFS : 짝수시간, 홀수시간의 첫 방문 시간을 기록
    {
        auto cur = q.front();
        q.pop();

        int v = cur.first;
        int vt = cur.second;
        int nvt = vt + 1;

        for (int nv : {2 * v, v - 1, v + 1})
        {
            if (nv < 0 || nv > 500000)
                continue;
            if (vis[nvt % 2][nv] != -1)
                continue;
            vis[nvt % 2][nv] = nvt;
            q.push({nv, nvt});
        }
    }

    int ans = 0;
    bool isFind = 0;

    while (k <= 500000)
    {
        // 수빈이가 동생보다 먼저 도착했던 곳이거나 같이 도착한 경우
        if (vis[ans % 2][k] <= ans)
        {
            isFind = 1;
            break;
        }
        k += ++ans;
    }

    if (isFind == 1)
    {
        cout << ans;
    }
    else // 동생의 이동이 500,000을 넘어 수빈이와 만나지 못한 경우
    {
        cout << -1;
    }
}
