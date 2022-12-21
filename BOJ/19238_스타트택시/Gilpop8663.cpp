#include <bits/stdc++.h>
using namespace std;

int n, m, k;

int arr[24][24];

pair<int, int> taxi;

pair<int, int> guest[24][24];

int stGuest[24][24];

bool ch[24][24] = {0};

queue<tuple<int, int, int>> q; // x,y,dist

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

pair<int, int> goGuest(int stX, int stY)
{
    int one = -1, two = -1;
    fill(&ch[0][0], &ch[23][24], 0);
    q.push({taxi.first, taxi.second, 0});

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        int x = get<0>(cur);
        int y = get<1>(cur);
        int dist = get<2>(cur);

        if (k < dist)
            continue;
        if (x == guest[stX][stY].first && y == guest[stX][stY].second)
        {
            k += dist;
            one = x;
            two = y;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 1 || ny < 1 || nx > n || ny > n)
                continue;
            if (arr[nx][ny] == 1 || ch[nx][ny] == 1)
                continue;
            ch[nx][ny] = 1;
            q.push({nx, ny, dist + 1});
        }
    }

    while (!q.empty())
    {
        q.pop();
    }

    return {one, two};
}

pair<int, int> findGuest()
{
    int one = -1, two = -1;
    q.push({taxi.first, taxi.second, 0});
    fill(&ch[0][0], &ch[23][24], 0);

    vector<pair<int, int>> loc;

    int minDist = 999;

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        int x = get<0>(cur);
        int y = get<1>(cur);
        int dist = get<2>(cur);

        if (k < dist)
            continue;

        if (dist == minDist && stGuest[x][y] == 1)
        {
            loc.push_back({x, y});
            continue;
        }

        if (stGuest[x][y] == 1 && minDist > dist)
        {
            minDist = dist;
            loc.push_back({x, y});
            continue;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 1 || ny < 1 || nx > n || ny > n)
                continue;
            if (arr[nx][ny] == 1 || ch[nx][ny] == 1)
                continue;

            ch[nx][ny] = 1;
            q.push({nx, ny, dist + 1});
        }
    }

    while (!q.empty())
    {
        q.pop();
    }

    if (minDist != 999)
    {
        sort(loc.begin(), loc.end());
        one = loc[0].first;
        two = loc[0].second;
        k -= minDist;
    }

    return {one, two};
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
            guest[i][j] = {-1, -1};
        }
    }

    cin >> taxi.first >> taxi.second;

    for (int i = 0; i < m; i++)
    {
        int stX, stY, enX, enY;
        cin >> stX >> stY >> enX >> enY;
        stGuest[stX][stY] = 1;

        guest[stX][stY] = {enX, enY};
    }

    int timer = m;
    while (timer--)
    {

        auto start = findGuest();

        if (start.first == -1)
        {
            cout << -1;
            return 0;
        }

        taxi.first = start.first;
        taxi.second = start.second;
        stGuest[start.first][start.second] = 0;

        auto end = goGuest(start.first, start.second);

        if (end.first == -1)
        {
            cout << -1;
            return 0;
        }

        taxi.first = end.first;
        taxi.second = end.second;
    }

    cout << k;
}