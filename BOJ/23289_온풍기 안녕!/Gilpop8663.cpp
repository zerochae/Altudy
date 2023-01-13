#include <bits/stdc++.h>
using namespace std;

int n, m, k;

int w;

int arr[22][22];

int wall[22][22];

int temperature[22][22];
int copy_temperature[22][22];

bool ch[22][22];
queue<tuple<int, int, int>> q; // x , y , 온도

int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};

int spreadDx[5] = {0, 0, 0, 0, 1};
int spreadDy[5] = {0, 0, -1, 0, 0};

int spreadKind[5] = {0, 9, 9, 8, 8};

vector<pair<int, int>> scoreTemp;

vector<tuple<int, int, int>> wallList;

// 오른쪽 ,왼쪽 , 위, 아래

int heaterDx[5][3] = {
    {0, 0, 0},
    {-1, 0, 1},
    {-1, 0, 1},
    {-1, -1, -1},
    {1, 1, 1}};

int heaterDy[5][3] = {
    {0, 0, 0},
    {1, 1, 1},
    {-1, -1, -1},
    {-1, 0, 1},
    {-1, 0, 1}};

// 오른쪽 왼쪽 위
int wallDx[5][3][2] = {
    {{0, 0}, {0, 0}, {0, 0}},
    {{0, -1}, {0, 0}, {1, 1}}, // 오른쪽 끝
    {{0, -1}, {0, 0}, {1, 1}}, // 왼쪽
    {{0, 0}, {0, 0}, {0, 0}},
    {{0, 1}, {1, 1}, {0, 1}},
};

int wallDy[5][3][2] = {
    {{0, 0}, {0, 0}, {0, 0}},
    {{0, 0}, {0, 0}, {0, 0}},
    {{0, -1}, {-1, -1}, {0, -1}},
    {{-1, -1}, {0, 0}, {0, 1}},
    {{-1, -1}, {0, 0}, {0, 1}},
};

int wallKind[5][3][2] = {
    {{0, 0}, {0, 0}, {0, 0}},
    {{8, 9}, {9, 9}, {8, 9}},
    {{8, 9}, {9, 9}, {8, 9}},
    {{9, 8}, {8, 8}, {9, 8}},
    {{9, 8}, {8, 8}, {9, 8}},
};

bool isWall(int k, int curX, int curY, int dir)
{
    for (int j = 0; j < 2; j++)
    {
        int nx = curX + wallDx[dir][k][j];
        int ny = curY + wallDy[dir][k][j];

        // if (nx < 1 || ny < 1 || nx > n || ny > m)
        //     return false;

        for (int i = 0; i < wallList.size(); i++)
        {
            int wallX = get<0>(wallList[i]);
            int wallY = get<1>(wallList[i]);
            int wallKindNumber = get<2>(wallList[i]);

            if (wallX == nx && wallY == ny && wallKind[dir][k][j] == wallKindNumber)
            {
                return true;
            }
        }
    }

    return false;
}

void calculateTemp(int x, int y)
{
    fill(&ch[0][0], &ch[21][22], 0);
    int dir = arr[x][y];

    int startX = x + dx[dir];
    int startY = y + dy[dir];

    ch[startX][startY] = 1;
    q.push({startX, startY, 5});

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        int curX = get<0>(cur);
        int curY = get<1>(cur);
        int curTemp = get<2>(cur);

        temperature[curX][curY] += curTemp;

        for (int k = 0; k < 3; k++) // 3갈래로 움직임
        {
            int nx = curX + heaterDx[dir][k];
            int ny = curY + heaterDy[dir][k];

            if (curTemp == 1)
                continue;
            if (nx < 1 || ny < 1 || nx > n || ny > m)
                continue;
            if (ch[nx][ny] == 1)
                continue;
            if (isWall(k, curX, curY, dir))
                continue;

            ch[nx][ny] = 1;
            q.push({nx, ny, curTemp - 1});
        }
    }
}

void turnOnHeater()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (arr[i][j] > 0)
            {
                calculateTemp(i, j);
            }
        }
    }
}

bool isSperad(int x, int y, int dir)
{
    int nx = x + spreadDx[dir];
    int ny = y + spreadDy[dir];

    // if (nx < 1 || ny < 1 || nx > n || ny > m)
    //     return true;

    for (int i = 0; i < wallList.size(); i++)
    {
        int wallX = get<0>(wallList[i]);
        int wallY = get<1>(wallList[i]);
        int wallKindNumber = get<2>(wallList[i]);

        if (wallX == nx && wallY == ny && spreadKind[dir] == wallKindNumber)
        {
            return true;
        }
    }

    return false;
}

void spreadOut()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            copy_temperature[i][j] = temperature[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (temperature[i][j] > 0)
            {
                vector<int> diff;
                vector<pair<int, int>> loc;
                for (int k = 1; k <= 4; k++)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx < 1 || ny < 1 || nx > n || ny > m)
                        continue;
                    if (isSperad(i, j, k))
                        continue;

                    int differenceTemp = abs(temperature[i][j] - temperature[nx][ny]) / 4;
                    if (differenceTemp == 0)
                        continue;

                    if (temperature[i][j] > temperature[nx][ny])
                    {
                        loc.push_back({nx, ny});
                        diff.push_back(differenceTemp);
                    }
                    // else if (temperature[i][j] < temperature[nx][ny])
                    // {
                    //     copy_temperature[i][j] += differenceTemp;
                    //     copy_temperature[nx][ny] -= differenceTemp;
                    // }
                }

                for (int k = 0; k < loc.size(); k++)
                {
                    int differenceTemp = diff[k];
                    auto curLoc = loc[k];

                    copy_temperature[i][j] -= differenceTemp;
                    copy_temperature[curLoc.first][curLoc.second] += differenceTemp;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            temperature[i][j] = copy_temperature[i][j];
        }
    }
}

void decreaseTemp(int minX, int minY, int maxX, int maxY)
{

    fill(&ch[0][0], &ch[21][22], 0);
    for (int i = 1; i <= m; i++)
    {
        if (ch[minX][i] == 1)
            continue;
        if (temperature[minX][i] > 0)
        {
            ch[minX][i] = 1;
            temperature[minX][i] -= 1;
        }
    }

    for (int i = 1; i <= m; i++)
    {
        if (ch[maxX][i] == 1)
            continue;
        if (temperature[maxX][i] > 0)
        {
            ch[maxX][i] = 1;
            temperature[maxX][i] -= 1;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (ch[i][minY] == 1)
            continue;
        if (temperature[i][minY] > 0)
        {
            ch[i][minY] = 1;
            temperature[i][minY] -= 1;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (ch[i][maxY] == 1)
            continue;
        if (temperature[i][maxY] > 0)
        {
            ch[i][maxY] = 1;
            temperature[i][maxY] -= 1;
        }
    }
}

void findMinBlock()
{
    // int minX = 99, minY = 99, maxX = 0, maxY = 0;
    // bool isMinXFind = 0;
    // bool isMinYFind = 0;
    // bool isMaxYFind = 0;
    // bool isMaxXFind = 0;

    // for (int i = 1; i <= n; i++) // 위쪽
    // {
    //     for (int j = 1; j <= m; j++)
    //     {
    //         if (isMinXFind == 1)
    //             break;
    //         if (temperature[i][j] > 0)
    //         {
    //             isMinXFind = 1;
    //             minX = i;
    //         }
    //     }
    // }

    // for (int i = 1; i <= m; i++) // 왼쪽
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         if (isMinYFind == 1)
    //             break;
    //         if (temperature[j][i] > 0)
    //         {
    //             isMinYFind = 1;
    //             minY = i;
    //             break;
    //         }
    //     }
    // }

    // for (int i = m; i >= 1; i--) // 오른쪽
    // {
    //     for (int j = n; j >= 1; j--)
    //     {
    //         if (isMaxYFind == 1)
    //             break;
    //         if (temperature[j][i] > 0)
    //         {
    //             isMaxYFind = 1;
    //             maxY = i;
    //             break;
    //         }
    //     }
    // }

    // for (int i = n; i >= 1; i--) // 아래
    // {
    //     for (int j = m; j >= 1; j--)
    //     {
    //         if (isMaxXFind == 1)
    //             break;
    //         if (temperature[j][i] > 0)
    //         {
    //             isMaxXFind = 1;
    //             maxX = i;
    //             break;
    //         }
    //     }
    // }

    decreaseTemp(1, 1, n, m);
}

bool isFinish()
{
    for (int i = 0; i < scoreTemp.size(); i++)
    {
        auto cur = scoreTemp[i];

        int x = cur.first;
        int y = cur.second;

        if (temperature[x][y] < k)
        {
            return false;
        }
    }

    return true;
}

void printTemperature()
{
    cout << "\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << temperature[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}
void printWall()
{
    cout << "\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << wall[i][j] << " ";
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

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int number;
            cin >> number;
            if (number == 5)
            {
                arr[i][j] = 0;
                scoreTemp.push_back({i, j});
            }
            else
            {
                arr[i][j] = number;
            }
        }
    }

    cin >> w;

    // fill(&wall[0][0], &wall[21][22], -9);

    for (int i = 0; i < w; i++)
    {
        int x, y, kind;
        cin >> x >> y >> kind;

        if (kind == 1)
        {
            wallList.push_back({x, y, 9});
        }
        if (kind == 0)
        {
            wallList.push_back({x, y, 8});
        }
    }

    int answer = 0;
    while (true)
    {

        turnOnHeater();
        spreadOut();
        findMinBlock();
        answer += 1;
        if (isFinish() || answer == 101)
        {
            break;
        }
    }

    // printTemperature();
    // printWall();

    cout << answer;
}

/*

왼쪽
9 6 1
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
1 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0

오른쪽
9 6 1
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 2
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0


아래
6 9 1
0 0 0 0 4 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0

위
6 9 1
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 3 0 0 0 0
0

벽 예제
7 8 1
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
1 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
1
3 4 1

7 8 1
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 2
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
1
3 4 1

7 8 1
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 2
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
1
3 4 1

7 8 1
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 2 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
2
3 4 1
3 5 0

7 8 1
0 0 0 0 0 0 0 0
0 0 0 0 4 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
3
4 4 1
5 4 0
5 6 0


7 8 1
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 3 0 0 0
3
4 4 1
5 4 0
5 6 0

7 8 1
0 0 0 0 0 0 0 0
0 0 0 0 4 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 3 0 0 0
3
4 4 1
5 4 0
5 6 0


3 3 1
0 0 0
0 0 0
0 0 0
3
3 2 0
3 1 1
1 2 1


5 8 13
0 0 0 0 0 0 0 0
4 4 4 4 4 4 4 4
0 0 0 0 0 0 0 0
0 0 0 0 0 5 0 0
3 3 3 3 3 3 3 3
5
3 6 1
3 6 0
4 4 1
5 4 0
5 6 0
*/