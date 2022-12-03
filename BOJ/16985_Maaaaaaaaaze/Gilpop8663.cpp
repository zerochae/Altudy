#include <bits/stdc++.h>
using namespace std;

int arr[6][6][6];

int dz[6] = {0, 0, 0, 0, 1, -1};
int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};

bool ch[6][6][6] = {0};

queue<tuple<int, int, int, int>> q;

int tmp[6][6];

int randomArr[6][6][6];
int ans = 2e9;
int n = 5;
vector<int> order;

void rotate(int k)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tmp[i][j] = arr[k][n - j - 1][i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[k][i][j] = tmp[i][j];
        }
    }

    return;
}

void print(int k)
{
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[k][i][j] << " ";
        }
        cout << "\n";
    }

    return;
}

int func()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                ch[i][j][k] = 0;
            }
        }
    }

    int cnt = 99999999;

    if (randomArr[0][0][0] == 0 || randomArr[4][4][4] == 0)
    {
        return cnt;
    }

    ch[0][0][0] = 1;
    q.push({0, 0, 0, 0});

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        int x = get<0>(cur);
        int y = get<1>(cur);
        int z = get<2>(cur);
        int how = get<3>(cur);

        if (x == 4 && y == 4 && z == 4)
        {
            cnt = min(cnt, how);
            continue;
        }

        for (int k = 0; k < 6; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            int nz = z + dz[k];

            if (nx < 0 || ny < 0 || nz < 0 || nx >= n || ny >= n || nz >= n)
                continue;
            if (ch[nx][ny][nz] == 1)
                continue;
            if (randomArr[nx][ny][nz] == 0)
                continue;

            ch[nx][ny][nz] = 1;
            q.push({nx, ny, nz, how + 1});
        }
    }

    return cnt;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                cin >> arr[i][j][k];
            }
        }
    }

    for (int i = 0; i < 5; i++)
        order.push_back(i);

    for (int i = 0; i < 4; i++)
    {
        if (i != 0)
        {
            rotate(0);
        }
        for (int j = 0; j < 4; j++)
        {
            if (j != 0)
            {
                rotate(1);
            }
            for (int k = 0; k < 4; k++)
            {
                if (k != 0)
                {
                    rotate(2);
                }
                for (int l = 0; l < 4; l++)
                {
                    if (l != 0)
                    {
                        rotate(3);
                    }
                    for (int o = 0; o < 4; o++)
                    {
                        if (o != 0)
                        {
                            rotate(4);
                        }
                        do
                        {
                            for (int i = 0; i < n; i++)
                            {
                                for (int j = 0; j < n; j++)
                                {

                                    for (int k = 0; k < n; k++)
                                    {
                                        randomArr[i][j][k] = arr[order[i]][j][k];
                                    }
                                }
                            }

                            ans = min(func(), ans);

                            if (ans == 12)
                            {
                                cout << ans;
                                return 0;
                            }

                        } while (next_permutation(order.begin(), order.end()));
                    }
                }
            }
        }
    }
    if (ans == 99999999)
    {
        cout << -1;
    }
    else
    {
        cout << ans;
    }
}
