#include <bits/stdc++.h>
using namespace std;

int n, m;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int arr[55][55];
int dist[55][55];

vector<pair<int, int>> virus;
queue<pair<int, int>> q;

vector<int> state;

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
            if (arr[i][j] == 2)
            {
                virus.push_back({i, j});
            }
        }
    }

    for (int i = 0; i < virus.size(); i++)
    {
        if (i < m)
        {
            state.push_back(1);
        }
        else
        {
            state.push_back(0);
        }
    }

    int ans = 1e9;
    do
    {
        int t = 0;

        for (int i = 0; i < n; i++)
            fill(dist[i], dist[i] + n, -1);

        for (int i = 0; i < state.size(); i++)
        {
            if (state[i] == 1)
            {
                int x = virus[i].first;
                int y = virus[i].second;
                q.push({x, y});
                dist[x][y] = 0;
            }
        }

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

                if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                    continue;
                if (dist[nx][ny] >= 0)
                    continue;
                if (arr[nx][ny] == 1)
                    continue;
                dist[nx][ny] = dist[x][y] + 1;
                if (arr[nx][ny] == 0)
                {
                    t = max(t, dist[nx][ny]);
                }
                q.push({nx, ny});
            }
        }

        bool flag = true;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] == 0 && dist[i][j] == -1)
                    flag = false;
            }
        }

        if (flag)
            ans = min(ans, t);
    }

    while (prev_permutation(state.begin(), state.end()));

    if (ans == 1e9)
    {
        cout << -1;
    }
    else
    {
        cout << ans;
    }
}
