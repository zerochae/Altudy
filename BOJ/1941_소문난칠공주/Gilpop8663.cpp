#include <bits/stdc++.h>
using namespace std;

string board[5];

bool mask[25] = {0};
int ans;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 5; i++)
    {
        cin >> board[i];
    }

    // 25명 중 칠공주가 될 사람의 후보 조합
    fill(mask + 7, mask + 25, 1);

    do
    {
        queue<pair<int, int>> q;

        //구성원 중 이다솜파의 수 , 가로세로로 인접한 사람의 수
        int dasom = 0, adj = 0;

        bool isp7[5][5] = {}, vis[5][5] = {};

        for (int i = 0; i < 25; i++)
        {
            if (!mask[i])
            {
                int x = i / 5, y = i % 5;

                isp7[x][y] = 1;

                if (q.empty())
                {
                    q.push({x, y});
                    vis[x][y] = 1;
                }
            }
        }

        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();
            int x = cur.first;
            int y = cur.second;
            adj++;
            dasom += board[x][y] == 'S';

            for (int k = 0; k < 4; k++)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5)
                    continue;
                if (vis[nx][ny] == 1 || isp7[nx][ny] == 0)
                    continue;
                q.push({nx, ny});
                vis[nx][ny] = 1;
            }
        }

        ans += (adj >= 7 && dasom >= 4);
    }

    while (next_permutation(mask, mask + 25));

    cout << ans;
}