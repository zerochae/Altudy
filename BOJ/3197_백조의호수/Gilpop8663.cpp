#include <bits/stdc++.h>
using namespace std;

int n, m;

char arr[1520][1520];
char tmp[1520][1520];

bool ch[1520][1520] = {0};
bool vis[1520][1520] = {0};

bool isPossible = 0;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<pair<int, int>> q;
queue<pair<int, int>> nxt_q;

queue<pair<int, int>> cur_water;
queue<pair<int, int>> nxt_water;

void melt()
{

    while (!nxt_water.empty())
    {
        auto cur = nxt_water.front();
        nxt_water.pop();
        cur_water.push(cur);
    }

    while (!cur_water.empty())
    {
        auto cur = cur_water.front();
        cur_water.pop();
        int x = cur.first;
        int y = cur.second;

        vis[x][y] = 1;

        if (arr[x][y] == 'X')
        {
            arr[x][y] = '.';
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (vis[nx][ny] == 1)
                continue;
            if (arr[nx][ny] == 'X')
            {
                vis[nx][ny] = 1;
                nxt_water.push({nx, ny});
            }
        }
    }

    return;
}

void print()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

int BFS()
{

    while (!nxt_q.empty())
    {
        auto cur = nxt_q.front();
        nxt_q.pop();

        q.push(cur);
    }

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        int x = cur.first;
        int y = cur.second;

        ch[x][y] = 1;

        if (arr[x][y] == 'X')
            continue;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (ch[nx][ny] == 1)
                continue;

            if (arr[nx][ny] == 'L')
            {
                isPossible = 1;
                return 3; // 찾았다면 3.
            }

            if (arr[nx][ny] == 'X')
            {
                ch[nx][ny] = 1;
                nxt_q.push({nx, ny});
                continue;
            }

            q.push({nx, ny});
            ch[nx][ny] = 1;
        }
    }

    return 2; // 못 찾았다면 2.
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (arr[i][j] == '.' || arr[i][j] == 'L')
            {
                for (int k = 0; k < 4; k++)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                        continue;
                    if (vis[nx][ny] == 1)
                        continue;
                    if (arr[nx][ny] == 'X')
                    {
                        vis[nx][ny] = 1;

                        nxt_water.push({nx, ny});
                    }
                }
            }
        }
    }

    int ans = 0;

    bool isFind = 0;
    for (int i = 0; i < n; i++)
    {
        if (isFind == 1)
            break;
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 'L')
            {
                ch[i][j] = 1;
                isFind = 1;
                q.push({i, j});
                break;
            }
        }
    }

    if (BFS() == 3)
    {
        cout << ans;
        return 0;
    }

    while (!isPossible)
    {
        while (!cur_water.empty())
            cur_water.pop();
        while (!q.empty())
            q.pop();
        ans++;
        melt();
        if (BFS() == 3)
        {
            cout << ans;
            return 0;
        }
    }

    // print();
    // cout
    //     << "\n";
}
