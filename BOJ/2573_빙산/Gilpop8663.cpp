#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[305][305];
int tmp[305][305];
bool ch[305][305] = {0};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<pair<int, int>> q;

bool isMelt()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] > 0)
                return false;
        }
    }
    return true;
}

void dis()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int cnt = 0;
            if (arr[i][j] > 0)
            {

                for (int k = 0; k < 4; k++)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                        continue;
                    if (arr[nx][ny] == 0)
                        cnt++;
                }

                if (arr[i][j] >= cnt)
                {
                    tmp[i][j] = arr[i][j] - cnt;
                }
                else
                {
                    tmp[i][j] = 0;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = tmp[i][j];
        }
    }
}

int check()
{
    int cnt = 0;
    fill(&ch[0][0], &ch[304][305], 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (ch[i][j] == 1)
                continue;
            if (arr[i][j] > 0)
            {
                cnt++;
                ch[i][j] = 1;
                q.push({i, j});
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

                    if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                        continue;
                    if (ch[nx][ny] == 1)
                        continue;
                    if (arr[nx][ny] > 0)
                    {
                        ch[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }

    return cnt;
}

void print()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    return;
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
    while (1)
    {
        if (isMelt())
            break;
        if (check() > 1)
        {
            cout << ans;
            return 0;
        }
        ans++;
        dis();
    }

    cout << "0";
    return 0;
}
