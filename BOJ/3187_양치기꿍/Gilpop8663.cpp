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

    int ansWolf = 0, ansSheep = 0;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
        {

            if (str[j] == '.')
            {
                arr[i][j] = 8;
            }
            else if (str[j] == '#')
            {
                arr[i][j] = 9;
            }
            else if (str[j] == 'v')
            {
                arr[i][j] = 1;
            }
            else if (str[j] == 'k')
            {
                arr[i][j] = 2;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            int sheep = 0;
            int wolf = 0;

            if (ch[i][j] == 1)
                continue;
            if (arr[i][j] != 9)
            {
                // 울타리가 아니라면
                ch[i][j] = 1;
                q.push({i, j});
            }

            while (!q.empty())
            {
                pair<int, int> cur = q.front();
                q.pop();

                int x = cur.first;
                int y = cur.second;

                if (arr[x][y] == 1)
                    wolf++;
                if (arr[x][y] == 2)
                    sheep++;

                for (int k = 0; k < 4; k++)
                {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (ch[nx][ny] == 1)
                        continue;
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m || arr[nx][ny] == 9)
                        continue;
                    q.push({nx, ny});
                    ch[nx][ny] = 1;
                }
            }

            if (sheep > wolf)
            {
                ansSheep += sheep;
            }
            else
            {
                ansWolf += wolf;
            }
        }
    }

    cout << ansSheep << " " << ansWolf << "\n";
}
