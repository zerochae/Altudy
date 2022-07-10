#include <bits/stdc++.h>
using namespace std;

int n, m, k;

int sum = 0;

string str;

bool arr[105][105] = {0};
bool ch[105][105] = {0};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<pair<int, int>> q;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    for (int i = 0; i < k; i++)
    {
        int num, num2;
        cin >> num >> num2;

        arr[num][num2] = 1;
    }

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int cnt = 0;
            if (ch[i][j] == 1)
                continue;
            if (arr[i][j] == 1)
            {
                q.push({i, j});
                ch[i][j] = 1;
            }

            while (!q.empty())
            {
                pair<int, int> cur = q.front();
                q.pop();

                int x = cur.first;
                int y = cur.second;

                cnt++;

                for (int l = 0; l < 4; l++)
                {
                    int nx = x + dx[l];
                    int ny = y + dy[l];
                    if (nx < 1 || ny < 1 || nx > n || ny > m)
                        continue;
                    if (ch[nx][ny] == 1)
                        continue;
                    if (arr[nx][ny] == 1)
                    {

                        q.push({nx, ny});
                        ch[nx][ny] = 1;
                    }
                }
            }

            if (cnt > 0)
            {
                ans = max(ans, cnt);
            }
        }
    }

    cout << ans << "\n";
}
