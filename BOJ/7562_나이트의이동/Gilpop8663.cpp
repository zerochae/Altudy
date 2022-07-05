#include <bits/stdc++.h>

using namespace std;

int t;

int n, curX, curY, scoreX, scoreY;

int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while (t--)
    {
        int ans = 0;

        bool ch[305][305] = {0};

        cin >> n;

        cin >> curX >> curY;

        cin >> scoreX >> scoreY;

        queue<tuple<int, int, int>> q;

        q.push({curX, curY, 0});
        ch[curX][curY] = 1;

        while (!q.empty())
        {
            tuple<int, int, int> cur = q.front();
            q.pop();

            int x = get<0>(cur);
            int y = get<1>(cur);
            int cnt = get<2>(cur);

            if (x == scoreX && y == scoreY)
            {
                ans = cnt;
            }

            for (int k = 0; k < 8; k++)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || ny < 0 || nx >= n || ny >= n || ch[nx][ny] == 1)
                    continue;
                q.push({nx, ny, cnt + 1});
                ch[nx][ny] = 1;
            }
        }

        cout << ans << "\n";
    }
}
