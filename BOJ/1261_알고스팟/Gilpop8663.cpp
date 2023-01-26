#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int n, m;

int arr[105][105];

int dist[105][105];

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
void printDist()
{
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int ch[105][105] = {0};
// queue<tuple<int, int, it>> q;

priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = str[j] - '0';
        }
    }

    // print();

    fill(&dist[0][0], &dist[104][105], 999);

    ch[0][0] = 1;
    q.push({0, 0, 0});

    int ans = 9999;

    while (!q.empty())
    {
        int x, y, destroy;

        tie(destroy, x, y) = q.top();
        q.pop();

        // cout << x << " " << y << " " << destroy << "\n";

        dist[x][y] = min(dist[x][y], destroy);

        if (x == n - 1 && y == m - 1)
        {
            ans = min(ans, destroy);
            continue;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (ch[nx][ny] == 1)
                continue;
            ch[nx][ny] = 1;
            if (arr[nx][ny] == 0)
            {
                q.push({destroy, nx, ny});
            }
            if (arr[nx][ny] == 1)
            {
                q.push({destroy + 1, nx, ny});
            }
        }
    }

    // printDist();

    cout << ans;
}
