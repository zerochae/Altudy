#include <bits/stdc++.h>
using namespace std;

int n;

int X1, Y1, X2, Y2;

bool ch[205][205] = {0};

queue<tuple<int, int, int>> q;

int dx[6] = {-2, -2, 0, 0, 2, 2};
int dy[6] = {-1, 1, -2, 2, -1, 1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    cin >> X1 >> Y1 >> X2 >> Y2;

    ch[X1][Y1] = 1;
    q.push({X1, Y1, 0});

    while (!q.empty())
    {
        tuple<int, int, int> cur = q.front();
        q.pop();

        int x = get<0>(cur);
        int y = get<1>(cur);
        int cnt = get<2>(cur);

        if (x == X2 && y == Y2)
        {
            cout << cnt;
            break;
        }

        for (int i = 0; i < 6; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (ch[nx][ny] == 1)
                continue;
            if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                continue;

            q.push({nx, ny, cnt + 1});
            ch[nx][ny] = 1;
        }
    }

    if (q.size() == 0)
    {
        cout << -1;
    }
}
