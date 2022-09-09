#include <bits/stdc++.h>
using namespace std;

int n;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

double dir[4];

int ch[30][30];

int E, W, S, N;

double res;

void func(pair<int, int> P, double pro)
{
    int x = P.first;
    int y = P.second;

    if (ch[x][y] == n + 1)
    {
        res += pro;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (ch[nx][ny] != 0)
            continue;
        ch[nx][ny] = ch[x][y] + 1;
        func({nx, ny}, pro * dir[i]);
        ch[nx][ny] = 0;
    }
}

// EW  WE NW WN  WNES

//

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < 4; i++)
    {
        double x;
        cin >> x;
        dir[i] = x / 100;
    }

    ch[15][15] = 1;
    func({15, 15}, 1.0);
    cout.precision(10);
    cout << fixed << res;
}
