#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[22][22];
int tmp[22][22];
bool ch[22][22][6] = {0};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

const int EMPTY = -999;

queue<pair<int, int>> q;

/*
3-시계 map[i][j] = tmp_map[y-1-j][i];
3-반시계 map[i][j] = tmp_map[j][x-1-i];
*/

void rotateArr()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tmp[i][j] = arr[j][n - i - 1];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = tmp[i][j];
        }
    }
}

void calculateGravity()
{
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == -1)
                continue;
            if (arr[i][j] == EMPTY)
                continue;

            int x = i, y = j, num = arr[i][j];
            while (true)
            {
                if (arr[x + 1][y] != EMPTY || arr[x + 1][y] == -1 || x + 1 >= n)
                {
                    break;
                }
                x += 1;
            }
            arr[i][j] = EMPTY;
            arr[x][y] = num;
        }
    }
}

void deleteBlock(int x, int y, int num)
{
    fill(&ch[0][0][0], &ch[21][21][6], 0);
    ch[x][y][num] = 1;
    q.push({x, y});

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        int x = cur.first;
        int y = cur.second;
        if (arr[x][y] == 0 || arr[x][y] == num)
        {
            arr[x][y] = EMPTY;
        }

        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                continue;
            if (ch[nx][ny][num] == 1)
                continue;
            if (arr[nx][ny] == -1)
                continue;
            if (arr[nx][ny] == num || arr[nx][ny] == 0)
            {
                ch[nx][ny][num] = 1;
                q.push({nx, ny});
            }
        }
    }
}

tuple<int, int, int, int, int> findBlock()
{
    vector<tuple<int, int, int, int, int>> record; // 블록 수 , 무지개 블록 수 , 가장 작은 행 , 가장 작은 열 , 번호
    fill(&ch[0][0][0], &ch[21][21][6], 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int num = arr[i][j];
            if (ch[i][j][num] == 1)
                continue;
            if (arr[i][j] > 0)
            {
                ch[i][j][num] = 1;
                q.push({i, j});

                int cnt = 0;
                int rainbowCnt = 0;
                int minX = i;
                int minY = j;

                while (!q.empty())
                {
                    auto cur = q.front();
                    q.pop();

                    int x = cur.first;
                    int y = cur.second;

                    if (arr[x][y] == num || arr[x][y] == 0)
                    {
                        cnt += 1;

                        if (arr[x][y] == num) // 기준 블록은 무지개 번호가 아니여야 한다.
                        {
                            if (minX > x)
                            {
                                minX = x;
                                minY = y;
                            }
                            else if (minX == x && minY > y)
                            {
                                minX = x;
                                minY = y;
                            }
                        }

                        if (arr[x][y] == 0) // 무지개 블록 개수
                        {
                            rainbowCnt += 1;
                        }
                    }

                    for (int k = 0; k < 4; k++)
                    {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                            continue;
                        if (ch[nx][ny][num] == 1)
                            continue;
                        if (arr[nx][ny] == -1)
                            continue;
                        if (arr[nx][ny] == num || arr[nx][ny] == 0)
                        {
                            ch[nx][ny][num] = 1;
                            q.push({nx, ny});
                        }
                    }
                }
                record.push_back({cnt, rainbowCnt, minX, minY, num});
            }
        }
    }

    for (int i = 0; i < record.size(); i++)
    {
        int rCnt = get<0>(record[i]);
        int rRainbowCnt = get<1>(record[i]);
        int rMinX = get<2>(record[i]);
        int rMinY = get<3>(record[i]);
        int rNum = get<4>(record[i]);
    }

    record.push_back({0, 0, 0, 0, 0});

    sort(record.begin(), record.end(), greater<tuple<int, int, int, int, int>>());

    return record[0];
}

void print()
{
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    int ans = 0;

    while (true)
    {
        // 1. 크기가 가장 큰 블록을 찾는다.
        tuple<int, int, int, int, int> cur = findBlock();

        int rCnt = get<0>(cur);
        int rRainbowCnt = get<1>(cur);
        int rMinX = get<2>(cur);
        int rMinY = get<3>(cur);
        int rNum = get<4>(cur);

        if (rCnt <= 1) // 블록 그룹이 없다면 중단. rCnt 가 1 이하일 경우 블록 그룹이 없다는 뜻
            break;

        // 2. 점수를 더한다.
        ans += rCnt * rCnt;

        // 3. 가장 큰 블록 그룹을 제거한다.
        deleteBlock(rMinX, rMinY, rNum);

        // 4. 중력을 적용한다.
        calculateGravity();

        // 5. 블록을 반시계방향으로 회전한다.
        rotateArr();

        // 6. 중력을 적용한다.
        calculateGravity();
    }

    cout << ans;
}
