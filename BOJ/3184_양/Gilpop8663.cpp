#include <bits/stdc++.h>
using namespace std;

int t, n, m;

int arr[255][255];
bool ch[255][255];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<pair<int, int>> q;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int ansS = 0, ansW = 0;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;

        for (int j = 0; j < m; j++)
        {
            if (str[j] == '.')
            {
                arr[i][j] == 9; // 빈땅
            }
            else if (str[j] == '#')
            {
                arr[i][j] = 5; // 울타리
            }
            else if (str[j] == 'o')
            {
                arr[i][j] = 1; // 양
            }
            else
            {
                arr[i][j] = 2; //늑대
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            int sheep = 0, wolf = 0;
            if (ch[i][j] == 1)
                continue;
            if (arr[i][j] != 5)
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

                if (arr[x][y] == 1)
                {
                    sheep++;
                }
                else if (arr[x][y] == 2)
                {
                    wolf++;
                }

                for (int k = 0; k < 4; k++)
                {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (nx < 0 || ny < 0 || nx >= n || ny >= m || ch[nx][ny] == 1 || arr[nx][ny] == 5)
                        continue;

                    q.push({nx, ny});
                    ch[nx][ny] = 1;
                }
            }

            if (wolf < sheep)
            {
                ansS += sheep;
            }
            else
            {
                ansW += wolf;
            }
        }
    }

    cout << ansS << " " << ansW;
}
