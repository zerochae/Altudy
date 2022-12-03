#include <bits/stdc++.h>
using namespace std;

int n, m, t;

int arr[55][55];

bool ch[55][55] = {0};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void rotateCircle(int x, int d)
{
    int tmp;

    if (d == 0)
    {

        tmp = arr[x][m];

        for (int i = m; i > 1; i--)
        {
            arr[x][i] = arr[x][i - 1];
        }
        arr[x][1] = tmp;
    }

    if (d == 1)
    {
        tmp = arr[x][1];

        for (int i = 1; i < m; i++)
        {
            arr[x][i] = arr[x][i + 1];
        }

        arr[x][m] = tmp;
    }

    return;
}

bool bfs()
{
    vector<pair<int, int>> numbers;
    fill(&ch[0][0], &ch[54][55], 0);
    queue<pair<int, int>> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            bool isFind = 0;
            int num = arr[i][j];
            if (num == -1)
                continue;

            ch[i][j] = 1;

            q.push({i, j});

            while (!q.empty())
            {
                auto cur = q.front();
                q.pop();
                int x = cur.first;
                int y = cur.second;

                int curNum = arr[x][y];

                if (y == m && arr[x][1] == curNum)
                {
                    ch[x][1] = 1;
                    isFind = 1;
                    q.push({x, 1});
                    numbers.push_back({x, 1});
                }

                for (int k = 0; k < 4; k++)
                {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (nx < 1 || ny < 1 || nx > n || ny > m)
                        continue;

                    if (ch[nx][ny] == 1)
                        continue;

                    if (arr[nx][ny] == curNum)
                    {
                        isFind = 1;
                        ch[nx][ny] = 1;
                        q.push({nx, ny});
                        numbers.push_back({nx, ny});
                    }
                }
            }

            if (isFind == 1)
            {
                numbers.push_back({i, j});
            }
        }
    }

    if (numbers.size() == 0)
    {
        return false;
    }

    for (int i = 0; i < numbers.size(); i++)
    {
        auto cur = numbers[i];

        int x = cur.first;
        int y = cur.second;

        arr[x][y] = -1;
    }

    return true;
}

void aver()
{

    double number = 0;
    double cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int num = arr[i][j];

            if (num == -1)
                continue;

            number += num;
            cnt++;
        }
    }

    double average = number / cnt;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int num = arr[i][j];
            if (num == -1)
                continue;

            if (num > average)
            {
                arr[i][j] -= 1;
                continue;
            }

            if (num < average)
            {
                arr[i][j] += 1;
                continue;
            }
        }
    }

    return;
}

void print()
{
    cout << "\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int calculateAns()
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (arr[i][j] == -1)
                continue;
            ans += arr[i][j];
        }
    }

    return ans;
}

void func(int x, int d, int k)
{

    for (int i = x; i <= n; i += x)
    {
        for (int j = 0; j < k; j++)
        {
            rotateCircle(i, d);
        }
    }

    if (bfs() == false)
    {
        aver();
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> t;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < t; i++)
    {
        int x, d, k;

        cin >> x >> d >> k;
        func(x, d, k);
    }

    cout << calculateAns();
}
