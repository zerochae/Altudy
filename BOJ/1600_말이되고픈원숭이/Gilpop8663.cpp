#include <bits/stdc++.h>
using namespace std;

int bX, bY, Kn;

int board[202][202];
// x,y ,부순 횟수
int dist[32][202][202];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int kx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int ky[8] = {1, -1, 2, -2, 2, -2, 1, -1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> Kn >> bY >> bX;

    for (int i = 0; i < bX; i++)
    {
        for (int j = 0; j < bY; j++)
        {
            cin >> board[i][j];
        }
        // cout << board[i];
    }
    // cout << Kn << bX << bY << board[0];

    // //[x좌표 , y좌표 , 부순 횟수] 로 큐를 구성한다.

    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});
    dist[0][0][0] = 1;
    // queue<tuple<int, int, int>> q;

    // q.push({0, 0, 0});
    // dist[0][0][0] = 1;

    while (!q.empty())
    {
        int x, y, k;
        tie(k, x, y) = q.front();
        q.pop();
        if (k < Kn)
        {
            for (int i = 0; i < 8; i++)
            {
                int nx = x + kx[i];
                int ny = y + ky[i];
                if (nx < 0 || ny < 0 || nx >= bX || ny >= bY)
                    continue;
                if (board[nx][ny])
                    continue;
                if (dist[k + 1][nx][ny])
                    continue;
                dist[k + 1][nx][ny] = dist[k][x][y] + 1;
                q.push({k + 1, nx, ny});
            }
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= bX || ny >= bY)
                continue;
            if (board[nx][ny])
                continue;
            if (dist[k][nx][ny])
                continue;
            dist[k][nx][ny] = dist[k][x][y] + 1;
            q.push({k, nx, ny});
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i < Kn + 1; i++)
        if (dist[i][bX - 1][bY - 1])
            ans = min(ans, dist[i][bX - 1][bY - 1]);
    if (ans != INT_MAX)
        cout << ans - 1;
    else
        cout << -1;
}
