#include <bits/stdc++.h>
using namespace std;

int n, m;

char arr[22][22];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int ch[22][22] = {0};

int startToTrash[22];
int trashToTrashLength[22][22];

pair<int, int> robot;

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    fill(&ch[0][0], &ch[21][22], INT_MAX);
    ch[x][y] = 0;

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        int x = cur.first;
        int y = cur.second;
        int dist = ch[x][y] + 1;

        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (arr[nx][ny] == 'x')
                continue;
            if (ch[nx][ny] <= dist)
                continue;
            q.push({nx, ny});
            ch[nx][ny] = dist;
        }
    }
}

int findMinPath(int x, int y, vector<pair<int, int>> &dirtyPoint)
{
    vector<int> trashOrder;
    int result = INT_MAX;

    // 시작점에서 쓰레기까지 위치 구하기
    bfs(x, y);

    for (int i = 0; i < dirtyPoint.size(); i++)
    {
        startToTrash[i] = ch[dirtyPoint[i].first][dirtyPoint[i].second];
    }

    // 각 쓰레기에서 다른 쓰레기까지 위치 구하기

    for (int i = 0; i < dirtyPoint.size(); i++)
    {
        bfs(dirtyPoint[i].first, dirtyPoint[i].second);

        for (int j = 0; j < dirtyPoint.size(); j++)
        {
            if (i == j)
                continue;
            trashToTrashLength[i][j] = ch[dirtyPoint[j].first][dirtyPoint[j].second];
        }
        trashOrder.push_back(i);
    }

    //쓰레기 줍는 순서 살펴보기

    do
    {
        int lengthSum = startToTrash[trashOrder[0]];

        for (int i = 0; i < trashOrder.size() - 1; i++)
        {
            if (trashToTrashLength[trashOrder[i]][trashOrder[i + 1]] == INT_MAX)
            {
                lengthSum = -1;
                break;
            }
            lengthSum += trashToTrashLength[trashOrder[i]][trashOrder[i + 1]];
        }

        if (lengthSum == -1)
        {
            continue;
        }

        result = min(result, lengthSum);
    } while (next_permutation(trashOrder.begin(), trashOrder.end()));

    if (result == INT_MAX)
    {
        result = -1;
    }
    return result;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> m >> n)
    {
        if (n == 0 && m == 0)
            break;

        fill(&ch[0][0], &ch[21][22], 0);
        fill(&trashToTrashLength[0][0], &trashToTrashLength[21][22], 0);

        vector<pair<int, int>> dirtyPoint;

        for (int i = 0; i < n; i++)
        {
            string str;
            cin >> str;

            for (int j = 0; j < m; j++)
            {
                arr[i][j] = str[j];
                if (arr[i][j] == 'o')
                {
                    robot.first = i;
                    robot.second = j;
                }
                if (arr[i][j] == '*')
                {
                    dirtyPoint.push_back({i, j});
                }
            }
        }

        int ans = findMinPath(robot.first, robot.second, dirtyPoint);

        cout << ans << "\n";
    }
}
