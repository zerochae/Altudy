#include <bits/stdc++.h>

using namespace std;

int n, k;

int s, x, y;

int arr[208][208];
bool ch[208][208] = {0};

vector<pair<int, int>> virus[1005];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void func()
{
    for (int i = 1; i <= k; i++)
    {
        // cout << i << "\n";

        int len = virus[i].size();
        for (int j = 0; j < len; j++)
        {
            // cout << virus[i][j].first << " " << virus[i][j].second << "\n";

            if (ch[virus[i][j].first][virus[i][j].second] == 1)
                continue;
            ch[virus[i][j].first][virus[i][j].second] = 1;
            for (int l = 0; l < 4; l++)
            {

                int nx = virus[i][j].first + dx[l];
                int ny = virus[i][j].second + dy[l];

                if (nx < 0 || ny < 0 || nx >= n || ny >= n || arr[nx][ny] != 0)
                    continue;
                arr[nx][ny] = arr[virus[i][j].first][virus[i][j].second];
                virus[arr[nx][ny]].push_back({nx, ny});
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];

            if (arr[i][j] != 0)
            {
                virus[arr[i][j]].push_back({i, j});
            }
        }
    }

    cin >> s >> x >> y;

    for (int i = 1; i <= s; i++)
    {
        func();
    }

    cout << arr[x - 1][y - 1];

    return 0;
}
