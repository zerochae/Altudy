#include <bits/stdc++.h>
using namespace std;

int n, m;

int N, M;

tuple<int, int, char> robots[105];
int ch[105][105] = {0};

void leftFunc(int num)
{
    int x = get<0>(robots[num]);
    int y = get<1>(robots[num]);
    char dir = get<2>(robots[num]);

    if (dir == 'N')
    {
        robots[num] = {x, y, 'W'};
    }
    else if (dir == 'W')
    {
        robots[num] = {x, y, 'S'};
    }
    else if (dir == 'S')
    {
        robots[num] = {x, y, 'E'};
    }
    else
    {
        robots[num] = {x, y, 'N'};
    }
    return;
}

void rightFunc(int num)
{
    int x = get<0>(robots[num]);
    int y = get<1>(robots[num]);
    char dir = get<2>(robots[num]);

    if (dir == 'N')
    {
        robots[num] = {x, y, 'E'};
    }
    else if (dir == 'W')
    {
        robots[num] = {x, y, 'N'};
    }
    else if (dir == 'S')
    {
        robots[num] = {x, y, 'W'};
    }
    else
    {
        robots[num] = {x, y, 'S'};
    }
    return;
}

int frontFunc(int num)
{
    int x = get<0>(robots[num]);
    int y = get<1>(robots[num]);
    char dir = get<2>(robots[num]);

    int nx, ny;
    if (dir == 'N')
    {
        nx = x;
        ny = y + 1;
    }
    else if (dir == 'W')
    {
        nx = x - 1;
        ny = y;
    }
    else if (dir == 'S')
    {
        nx = x;
        ny = y - 1;
    }
    else
    {
        nx = x + 1;
        ny = y;
    }

    if (nx <= 0 || ny <= 0 || nx > n || ny > m)
    {
        return 1;
    }
    if (ch[nx][ny] > 0)
    {
        return 2;
    }
    ch[x][y] = 0;
    ch[nx][ny] = num;

    robots[num] = {nx, ny, dir};

    return 0;
}

void coutFunc(int num)
{
    int x = get<0>(robots[num]);
    int y = get<1>(robots[num]);
    char dir = get<2>(robots[num]);

    int nx, ny;
    if (dir == 'N')
    {
        nx = x;
        ny = y + 1;
    }
    else if (dir == 'W')
    {
        nx = x - 1;
        ny = y;
    }
    else if (dir == 'S')
    {
        nx = x;
        ny = y - 1;
    }
    else
    {
        nx = x + 1;
        ny = y;
    }

    if (nx <= 0 || ny <= 0 || nx > n || ny > m)
    {
        cout << "Robot " << num << " crashes into the wall";
        return;
    }
    if (ch[nx][ny] > 0)
    {
        cout << "Robot " << num << " crashes into robot " << ch[nx][ny];
        return;
    }
    return;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        int x, y;
        char dir;
        cin >> x >> y >> dir;
        ch[x][y] = i;
        robots[i] = {x, y, dir};
    }

    for (int j = 0; j < M; j++)
    {
        int who, many;
        char command;

        cin >> who >> command >> many;

        if (command == 'F')
        {
            bool isFind = 0;
            while (many--)
            {
                if (frontFunc(who) != 0)
                {
                    isFind = 1;
                    break;
                }
            }

            if (isFind == 1)
            {
                coutFunc(who);
                return 0;
            }
        }
        else if (command == 'L')
        {
            while (many--)
            {
                leftFunc(who);
            }
        }
        else if (command == 'R')
        {
            while (many--)
            {
                rightFunc(who);
            }
        }
    }
    cout << "OK";
}
