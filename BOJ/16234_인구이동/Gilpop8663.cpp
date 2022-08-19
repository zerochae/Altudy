#include <bits/stdc++.h>
using namespace std;

int n, L, R;

int arr[55][55];
int tmp[55][55];
bool ch[55][55] = {0};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<pair<int, int>> q;
queue<pair<int, int>> sq;

bool check()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int num = arr[i][j];
            for (int k = 0; k < 4; k++)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                    continue;
                if (abs(arr[i][j] - arr[nx][ny]) >= L && abs(arr[i][j] - arr[nx][ny]) <= R)
                    return false;
            }
        }
    }
    return true;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> L >> R;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    int ans = 0;
    while (check() == false)
    {
        fill(&ch[0][0], &ch[n - 1][n], false);

        ans++;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {

                int num = arr[i][j];

                if (ch[i][j] == 1)
                    continue;
                ch[i][j] = 1;
                q.push({i, j});
                sq.push({i, j});

                int sum = 0;

                while (!q.empty())
                {
                    auto cur = q.front();
                    q.pop();
                    int x = cur.first;
                    int y = cur.second;

                    sum += arr[x][y];

                    for (int k = 0; k < 4; k++)
                    {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                            continue;
                        if (ch[nx][ny] == 1)
                            continue;
                        if (abs(arr[x][y] - arr[nx][ny]) < L || abs(arr[x][y] - arr[nx][ny]) > R)
                            continue;
                        ch[nx][ny] = 1;
                        q.push({nx, ny});
                        sq.push({nx, ny});
                    }
                }

                // cout << sum << " " << sq.size() << " ";
                int div = sum / sq.size();

                while (!sq.empty())
                {
                    auto cur = sq.front();
                    sq.pop();

                    int x = cur.first;
                    int y = cur.second;

                    arr[x][y] = div;
                }
            }
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    cout
        << ans;
}
