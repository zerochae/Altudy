#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[105][105];
bool ch[105][105] = {0};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<pair<int, int>> q;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;

    int ansW = 0, ansB = 0;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            if (str[j] == 'W')
            {
                arr[i][j] = 1;
            }
            else
            {
                arr[i][j] = 2;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            int cnt = 0;
            if (ch[i][j] == 1)
                continue;

            q.push({i, j});
            ch[i][j] = 1;

            while (!q.empty())
            {
                pair<int, int> cur = q.front();
                q.pop();

                int x = cur.first;
                int y = cur.second;

                cnt++;

                int color = arr[x][y];
                for (int k = 0; k < 4; k++)
                {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (nx < 0 || ny < 0 || nx >= n || ny >= m || ch[nx][ny] == 1)
                        continue;
                    if (color == arr[nx][ny])
                    {
                        q.push({nx, ny});
                        ch[nx][ny] = 1;
                    }
                }
            }

            if (cnt > 0)
            {
                if (arr[i][j] == 1)
                {
                    ansW += cnt * cnt;
                }
                else
                {
                    ansB += cnt * cnt;
                }
            }
        }
    }
    cout << ansW << " " << ansB;
}
