#include <bits/stdc++.h>
using namespace std;

int n, m, k;

bool arr[105][105] = {0};
bool ch[105][105] = {0};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<tuple<int, int, int>> q;

vector<int> ans;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    for (int i = 0; i < k; i++)
    {
        int lX, rX, lY, rY;

        cin >> lX >> lY >> rX >> rY;

        for (int j = n - lY - 1; j >= n - rY; j--)
        {
            for (int k = lX; k < rX; k++)
            {
                arr[j][k] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // cout << arr[i][j] << " ";
            bool isFind = 0;
            int tmp = 0;
            if (ch[i][j] == 1)
                continue;
            if (arr[i][j] == 0)
            {
                isFind = 1;
                q.push({i, j, 0});
                ch[i][j] = 1;
            }

            while (!q.empty())
            {
                tuple<int, int, int> cur = q.front();

                q.pop();

                int x = get<0>(cur);
                int y = get<1>(cur);
                int cnt = get<2>(cur);

                tmp++;

                for (int k = 0; k < 4; k++)
                {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (nx < 0 || ny < 0 || nx >= n || ny >= m || ch[nx][ny] == 1)
                        continue;

                    if (arr[nx][ny] == 0)
                    {
                        q.push({nx, ny, cnt + 1});
                        ch[nx][ny] = 1;
                    }
                }
            }

            if (isFind == 1)
            {
                ans.push_back(tmp);
            }
        }
        // cout << "\n";
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << "\n";

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}