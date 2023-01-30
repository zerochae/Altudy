#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[105][105];

bool ch[105][105] = {0};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int>> q;

int countCheese()
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (arr[i][j] == 1)
            {
                cnt += 1;
            }
        }
    }

    return cnt;
}

void airBFS()
{
    fill(&ch[0][0], &ch[104][105], 0);
    ch[0][0] = 1;
    q.push({0, 0});

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        int x = cur.first;
        int y = cur.second;

        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx < 0 || ny < 0 || nx >= n + 1 || ny >= m + 1)
                continue;
            if (ch[nx][ny] == 1)
                continue;
            if (arr[nx][ny] == 1)
                continue;
            ch[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
}

void airPrint()
{
    cout << "\n";
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            cout << ch[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}
void print()
{
    cout << "\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void BFS()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (arr[i][j] == 0)
                continue;
            for (int k = 0; k < 4; k++)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx < 0 || ny < 0 || nx >= n + 1 || ny >= m + 1)
                    continue;
                if (ch[nx][ny] == 1)
                {
                    arr[i][j] = 0;
                    break;
                }
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        }
    }

    int count = 0;
    int ans = 0;
    while (countCheese() > 0)
    {
        ans = countCheese();
        count += 1;
        airBFS();
        BFS();
    }

    cout << count << "\n";
    cout << ans;
}
