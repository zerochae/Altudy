#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[10][10];
bool ch[10][10] = {0};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int tmp[10][10];

queue<pair<int, int>> q;

int maxNum = 0;

int BFS(int copyArr[10][10])
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (copyArr[i][j] == 2)
            {
                if (ch[i][j] == 1)
                    continue;
                q.push({i, j});
                ch[i][j] = 1;

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
                        if (copyArr[nx][ny] == 0)
                        {
                            ch[nx][ny] = 1;
                            copyArr[nx][ny] = 2;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (copyArr[i][j] == 0)
            {
                ans++;
            }
        }
    }

    return ans;
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

void func(int cnt, int r, int c)
{

    if (cnt == 3)
    {
        fill(&ch[0][0], &ch[9][10], 0);
        copy(&arr[0][0], &arr[0][0] + 100, &tmp[0][0]);
        maxNum = max(maxNum, BFS(tmp));
        // print();
        // cout << "\n";
        return;
    }

    int c2 = 0;
    for (int i = r; i < n; i++)

    {
        if (i == r)
        {
            c2 = c;
        }
        else
        {
            c2 = 0;
        }
        for (int j = c2; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                // if (ch[i][j] == 1)
                //     continue;

                // ch[i][j] = 1;
                arr[i][j] = 1;
                func(cnt + 1, i, j);
                arr[i][j] = 0;
                // ch[i][j] = 0;
            }
        }
    }
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

    func(0, 0, 0);

    cout << maxNum;
}
