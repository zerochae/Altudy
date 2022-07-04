#include <bits/stdc++.h>
using namespace std;

int n;

int arr[105][105];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<pair<int, int>> q;

int func(int k)
{

    bool ch[105][105] = {0};
    bool ch2[105][105] = {0};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] <= k)
            {

                continue;
            }
            ch[i][j] = 1;
        }
    }

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (ch2[i][j] == 1)
                continue;
            if (ch[i][j] == 1)
            {
                result++;
                q.push({i, j});
                ch2[i][j] = 1;
            }

            while (!q.empty())
            {
                pair<int, int> cur = q.front();
                q.pop();

                int x = cur.first;
                int y = cur.second;

                for (int t = 0; t < 4; t++)
                {
                    int nx = x + dx[t];
                    int ny = y + dy[t];

                    if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                        continue;
                    if (ch2[nx][ny] == 1)
                        continue;
                    if (ch[nx][ny] == 1)
                    {
                        q.push({nx, ny});
                        ch2[nx][ny] = 1;
                    }
                }
            }
        }
    }

    return result;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    int ans = 1;

    for (int i = 1; i <= 100; i++)
    {
        int num = func(i);
        ans = max(ans, num);
    }

    cout << ans << "\n";
}
