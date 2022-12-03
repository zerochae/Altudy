#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int ans = 100;

int dist[11][11][11][11];

string arr[11];

pair<int, int> red, blue;

int func()
{
    queue<tuple<int, int, int, int>> q;
    q.push({red.X, red.Y, blue.X, blue.Y});
    dist[red.X][red.Y][blue.X][blue.Y] = 0;

    while (!q.empty())
    {
        int rx, ry, bx, by;
        tie(rx, ry, bx, by) = q.front();
        q.pop();

        int cnt = dist[rx][ry][bx][by];

        if (cnt >= 10)
            return -1;

        for (int i = 0; i < 4; i++)
        {
            int n_bx = bx, n_by = by, n_rx = rx, n_ry = ry;

            // Blue 이동
            while (arr[n_bx + dx[i]][n_by + dy[i]] == '.')
            {
                n_bx += dx[i];
                n_by += dy[i];
            }

            // Blue가 탈출 시 실패
            if (arr[n_bx + dx[i]][n_by + dy[i]] == 'O')
                continue;

            // Red 이동
            while (arr[n_rx + dx[i]][n_ry + dy[i]] == '.')
            {
                n_rx += dx[i];
                n_ry += dy[i];
            }

            // Red가 탈출 시 정답
            if (arr[n_rx + dx[i]][n_ry + dy[i]] == 'O')
                return cnt + 1;

            // Red와 Blue가 겹쳐진 경우 늦게 출발한 구슬을 한칸 뒤로 이동

            if ((n_rx == n_bx) && (n_ry == n_by))
            {
                if (i == 0) //아래쪽으로 이동
                {
                    rx < bx ? n_rx-- : n_bx--;
                }
                else if (i == 1) // 오른쪽으로 이동
                {
                    ry < by ? n_ry-- : n_by--;
                }
                else if (i == 2) // 위쪽으로 이동
                {
                    rx > bx ? n_rx++ : n_bx++;
                }
                else if (i == 3) //왼쪽으로 이동
                {
                    ry > by ? n_ry++ : n_by++;
                }
            }

            if (dist[n_rx][n_ry][n_bx][n_by] != -1)
                continue;
            dist[n_rx][n_ry][n_bx][n_by] = cnt + 1;
            q.push({n_rx, n_ry, n_bx, n_by});
        }
    }

    return -1;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                fill(dist[i][j][k], dist[i][j][k] + 10, -1);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];

        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 'R')
            {
                red.X = i;
                red.Y = j;
                arr[i][j] = '.';
            }
            if (arr[i][j] == 'B')
            {
                blue.X = i;
                blue.Y = j;
                arr[i][j] = '.';
            }
        }
    }

    cout << func();
}
