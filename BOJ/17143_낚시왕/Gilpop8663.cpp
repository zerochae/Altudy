#include <bits/stdc++.h>
using namespace std;

int n, m, k;

struct Shark
{
    int speed;
    int dir;
    int sSize;
};

Shark shark[105][105];
Shark tmp[105][105];

int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, 1, -1};

void reset()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            tmp[i][j].dir = 0;
            tmp[i][j].sSize = 0;
            tmp[i][j].speed = 0;
        }
    }
    return;
}

void copyShark()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            shark[i][j].dir = tmp[i][j].dir;
            shark[i][j].speed = tmp[i][j].speed;
            shark[i][j].sSize = tmp[i][j].sSize;
        }
    }
    return;
}

tuple<int, int, int> moveShark(int x, int y, int dir, int speed)
{
    int nx = x;
    int ny = y;

    int nDir = dir;

    if (nDir == 1 && nx == 1)
    {
        nDir = 2;
    }
    else if (nDir == 2 && nx == n)
    {
        nDir = 1;
    }

    else if (nDir == 3 && ny == m)
    {
        nDir = 4;
    }
    else if (nDir == 4 && ny == 1)
    {
        nDir = 3;
    }

    if (dir == 1 || dir == 2)
    {
        auto mv = speed % (2 * (n - 1));

        while (mv--)

        {
            nx += dx[nDir];
            ny += dy[nDir];

            if (nDir == 1 && nx == 1)
            {
                nDir = 2;
            }
            else if (nDir == 2 && nx == n)
            {
                nDir = 1;
            }

            else if (nDir == 3 && ny == m)
            {
                nDir = 4;
            }
            else if (nDir == 4 && ny == 1)
            {
                nDir = 3;
            }
        }
        return {nx, ny, nDir};
    }
    else if (dir == 3 || dir == 4)
    {
        auto mv = speed % (2 * (m - 1));

        while (mv--)

        {
            nx += dx[nDir];
            ny += dy[nDir];

            if (nDir == 1 && nx == 1)
            {
                nDir = 2;
            }
            else if (nDir == 2 && nx == n)
            {
                nDir = 1;
            }

            else if (nDir == 3 && ny == m)
            {
                nDir = 4;
            }
            else if (nDir == 4 && ny == 1)
            {
                nDir = 3;
            }
        }
        return {nx, ny, nDir};
    }
    return {nx, ny, nDir};
}

void move()
{

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (shark[i][j].sSize > 0)
            {
                tuple<int, int, int> location = moveShark(i, j, shark[i][j].dir, shark[i][j].speed);

                int x = get<0>(location);
                int y = get<1>(location);
                int nDir = get<2>(location);

                if (tmp[x][y].sSize < shark[i][j].sSize)
                {
                    tmp[x][y].sSize = shark[i][j].sSize;
                    tmp[x][y].speed = shark[i][j].speed;
                    tmp[x][y].dir = nDir;
                }
                shark[i][j].speed = 0;
                shark[i][j].dir = 0;
                shark[i][j].sSize = 0;
            }
        }
    }
}

int fishing(int x)
{
    for (int i = 1; i <= n; i++)
    {
        if (shark[i][x].sSize > 0)
        {
            int sharkSize = shark[i][x].sSize;
            shark[i][x].dir = 0;
            shark[i][x].speed = 0;
            shark[i][x].sSize = 0;
            return sharkSize;
        }
    }
    return 0;
}

void print()
{
    cout << "\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << shark[i][j].sSize << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    for (int i = 0; i < k; i++)
    {
        int r, c, s, d, z;

        cin >> r >> c >> s >> d >> z;
        shark[r][c] = {s, d, z};
    }

    int human = 0;
    int ans = 0;
    while (human < m)
    {
        // cout << human << "\n";
        human++;
        // print();
        ans += fishing(human);
        reset();
        move();
        copyShark();
        // print();
    }

    cout << ans;
}
