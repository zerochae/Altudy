#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[55][55];

vector<pair<int, int>> virus;

vector<int> state;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool check(bool ch[55][55])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (ch[i][j] == 0 && arr[i][j] != 1)
                return false;
        }
    }
    return true;
}

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

    int ans = 9999;

    do
    {
        bool ch[55][55] = {0};
        queue<pair<int, int>> q;
        queue<pair<int, int>> q2;
        for (int i = 0; i < state.size(); i++)
        {
            if (state[i] == 1)
            {
                int x = virus[i].first;
                int y = virus[i].second;
                q.push({x, y});
                ch[x][y] = 1;
            }
        }

        int time = 110;
        int count = 0;

        while (time--)
        {
            if (check(ch))
            {
                ans = min(ans, count);
                break;
            }
            count++;
            while (!q.empty())
            {
                auto cur = q.front();
                q.pop();

                int x = cur.first;
                int y = cur.second;

                for (int i = 0; i < 4; i++)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                        continue;
                    if (ch[nx][ny] == 1)
                        continue;
                    if (arr[nx][ny] == 1)
                        continue;
                    q2.push({nx, ny});
                    ch[nx][ny] = 1;
                }
            }

            while (!q2.empty())
            {
                auto cur = q2.front();
                q2.pop();
                q.push(cur);
            }
        }
    } while (prev_permutation(state.begin(), state.end()));

    if (ans == 9999)
    {
        cout << -1;
    }
    else
    {
        cout << ans;
    }
}
