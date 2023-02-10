#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[105][105];

int air[105][105];

bool ch[105][105] = {0};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int>> q;

bool isNotEmpty()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1)
                return true;
        }
    }

    return false;
}

void airBFS()
{
    fill(&air[0][0], &air[104][105], 0);
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

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (ch[nx][ny] == 1)
                continue;
            if (arr[nx][ny] == 1)
            {
                air[nx][ny] += 1;
                continue;
            }
            ch[nx][ny] = 1;
            q.push({nx, ny});
        }
    }

    return;
}

void melting()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (air[i][j] >= 2)
            {
                arr[i][j] = 0;
            }
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
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}
void printAir()
{
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << air[i][j] << " ";
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
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    int ans = 0;

    while (isNotEmpty())
    {
        ans += 1;
        airBFS();
        melting();
    }

    cout << ans;
}
