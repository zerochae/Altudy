#include <bits/stdc++.h>
using namespace std;

int n, k;

int arr[14][14];

int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};

tuple<int, int, int> hor[11];

stack<int> whereH[14][14];

vector<int> getHorses(int x, int y, int kind)
{

    vector<int> tmp;

    while (!whereH[x][y].empty())
    {
        int cur = whereH[x][y].top();
        whereH[x][y].pop();
        tmp.push_back(cur);
        if (cur == kind)
        {
            break;
        }
    }

    reverse(tmp.begin(), tmp.end());
    return tmp;
}

int horseMove(int x, int y, int dir, int kind)
{
    int nx = x + dx[dir];
    int ny = y + dy[dir];

    if (arr[nx][ny] == 2 || nx < 1 || ny < 1 || nx > n || ny > n)
    {

        if (dir == 1)
        {
            dir = 2;
        }
        else if (dir == 2)
        {
            dir = 1;
        }
        else if (dir == 3)
        {
            dir = 4;
        }
        else if (dir == 4)
        {
            dir = 3;
        }

        nx += dx[dir] * 2;
        ny += dy[dir] * 2;

        hor[kind] = {x, y, dir};
        if (arr[nx][ny] == 2 || nx < 1 || ny < 1 || nx > n || ny > n)
            return 0;
    }

    vector<int> horses = getHorses(x, y, kind);

    if (arr[nx][ny] == 0)
    {
        for (int i = 0; i < horses.size(); i++)
        {
            int cur = horses[i];
            int horseDir = get<2>(hor[cur]);
            hor[cur] = {nx, ny, horseDir};
            whereH[nx][ny].push(cur);
            if (whereH[nx][ny].size() >= 4)
            {
                return cur;
            }
        }
    }
    if (arr[nx][ny] == 1)
    {
        for (int i = horses.size() - 1; i >= 0; i--)
        {
            int cur = horses[i];
            int horseDir = get<2>(hor[cur]);
            hor[cur] = {nx, ny, horseDir};
            whereH[nx][ny].push(cur);
            if (whereH[nx][ny].size() >= 4)
            {
                return cur;
            }
        }
    }
    return 0;
}

void print()
{
    cout << "\n";
    for (int i = 1; i <= k; i++)
    {
        int x = get<0>(hor[i]);
        int y = get<1>(hor[i]);
        int dir = get<2>(hor[i]);

        cout << i << " " << x << " " << y << " " << dir << "\n";
    }
    cout << "\n";
}

void sizePrint()
{
    cout << "\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << whereH[i][j].size() << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= k; i++)
    {
        int x, y, dir;
        cin >> x >> y >> dir;
        hor[i] = {x, y, dir};
        whereH[x][y].push(i);
    }

    int timer = 1000;
    int ans = 0;
    while (timer--)
    {
        ans++;
        for (int i = 1; i <= k; i++)
        {

            int x = get<0>(hor[i]);
            int y = get<1>(hor[i]);
            int dir = get<2>(hor[i]);

            int movement = horseMove(x, y, dir, i);

            if (movement >= 1)
            {
                cout << ans;
                return 0;
            }
        }
    }

    cout << -1;
    return 0;
}
