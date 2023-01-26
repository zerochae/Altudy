#include <bits/stdc++.h>
using namespace std;
int n, m;

string arr[55][55];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool ch[55][55] = {0};

queue<pair<int, int>> q;
queue<pair<int, int>> water;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;

        for (int j = 0; j < m; j++)
        {
            arr[i][j] = str[j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == "S")
            {
                ch[i][j] = 1;
                q.push({i, j});
            }
            if (arr[i][j] == "*")
            {
                ch[i][j] = 1;
                water.push({i, j});
            }
        }
    }

    int timer = 0;

    while (true)
    {

        if (water.empty() && q.empty())
        {
            break;
        }

        queue<pair<int, int>> copy_water;
        while (!water.empty())
        {
            auto cur = water.front();
            water.pop();
            int x = cur.first;
            int y = cur.second;

            for (int k = 0; k < 4; k++)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;
                if (ch[nx][ny] == 1)
                    continue;
                if (arr[nx][ny] == "X" || arr[nx][ny] == "D")
                    continue;
                ch[nx][ny] = 1;
                copy_water.push({nx, ny});
            }
        }

        while (!copy_water.empty())
        {
            auto cur = copy_water.front();
            copy_water.pop();

            water.push(cur);
        }

        queue<pair<int, int>> copy_q;

        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();

            int x = cur.first;
            int y = cur.second;

            if (arr[x][y] == "D")
            {
                cout << timer;
                return 0;
            }

            for (int k = 0; k < 4; k++)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;
                if (ch[nx][ny] == 1)
                    continue;
                if (arr[nx][ny] == "X")
                    continue;
                ch[nx][ny] = 1;
                copy_q.push({nx, ny});
            }
        }

        while (!copy_q.empty())
        {
            auto cur = copy_q.front();
            copy_q.pop();

            q.push(cur);
        }

        timer += 1;
    }

    cout << "KAKTUS";
}
