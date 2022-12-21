#include <bits/stdc++.h>
using namespace std;

int n, m, d;

int arr[20][20];
int copy_arr[20][20];
int tmp[20][20];
bool ch[20][20];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<bool> state;

void move() // 적의 움직임
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            tmp[i][j] = copy_arr[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        copy_arr[0][i] = 0;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            copy_arr[i][j] = tmp[i - 1][j];
        }
    }

    return;
}

void print()
{
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << copy_arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int attack(vector<bool> &archer)
{

    int enemy = 0;

    vector<pair<int, int>> location;

    queue<pair<int, int>> q;

    for (int k = 0; k < m; k++)
    {
        bool isAttack = 0;
        int dist = 9999;
        fill(&ch[0][0], &ch[19][20], 0);
        if (archer[k] == 1)
            continue;

        vector<pair<int, int>> enemiesLocation;

        ch[n][k] = 1;
        q.push({n, k});

        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();

            int x = cur.first;
            int y = cur.second;
            int curDist = abs(n - x) + abs(k - y);
            if (copy_arr[x][y] == 1 && dist >= curDist)
            {
                dist = curDist;
                enemiesLocation.push_back({y, x}); // 거리가 같다면 왼쪽부터 잡는 다는 조건을 위해 y, x를 넣어줌
                continue;
            }

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                int nDist = abs(n - nx) + abs(k - ny);

                if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;
                if (ch[nx][ny] == 1)
                    continue;
                if (nDist > d)
                    continue;
                ch[nx][ny] = 1;
                q.push({nx, ny});
            }
        }

        sort(enemiesLocation.begin(), enemiesLocation.end()); // y,x 기준으로 정렬

        if (enemiesLocation.size() > 0)
        {
            location.push_back({enemiesLocation[0].second, enemiesLocation[0].first}); // 헷갈리지 않기 위해 다시 x, y로 넣어줌
        }
    }

    for (int i = 0; i < location.size(); i++)
    {
        auto cur = location[i];

        int x = cur.first;
        int y = cur.second;
        if (copy_arr[x][y] == 0)
            continue;
        copy_arr[x][y] = 0;
        enemy += 1;
    }

    return enemy;
}

bool isEmpty()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (copy_arr[i][j] == 1)
                return true;
        }
    }

    return false;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> d;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        state.push_back(0);
    }

    for (int i = 3; i < m; i++)
    {
        state.push_back(1);
    }

    int answer = 0;

    do
    {
        int enemy = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                copy_arr[i][j] = arr[i][j];
            }
        }

        while (isEmpty())
        {
            enemy += attack(state);
            move();
        }

        answer = max(answer, enemy);
    } while (next_permutation(state.begin(), state.end()));

    cout << answer;
}
