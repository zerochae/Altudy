#include <bits/stdc++.h>
using namespace std;

int t, n, m;

const int MX = 120;

char arr[MX][MX];

int vis[MX][MX];

int ans = 0;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while (t--)
    {

        queue<pair<int, int>> Q;
        queue<pair<int, int>> door[26]; // 아직 키가 없어서 방문하지 못하는 곳의 좌표를 저장 ,추후 키가 생기면 방문할 예정
        cin >> n >> m;
        int key[26] = {};
        int cnt = 0;

        fill(&arr[0][0], &arr[104][MX], 0);
        fill(&vis[0][0], &vis[104][MX], 0);

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> arr[i][j];
            }
        }

        string keys;
        cin >> keys;

        for (auto c : keys)
        {
            key[c - 'a'] = 1;
        }

        Q.push({0, 0});
        vis[0][0] = 1;

        while (!Q.empty())
        {
            auto cur = Q.front();
            Q.pop();

            int x = cur.first;
            int y = cur.second;

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || ny < 0 || nx > n + 1 || ny > m + 1)
                    continue;
                if (vis[nx][ny] == 1 || arr[nx][ny] == '*')
                    continue;

                vis[nx][ny] = 1;

                // 1. 열쇠

                if (islower(arr[nx][ny]))
                {

                    int k = arr[nx][ny] - 'a';
                    key[k] = 1;

                    while (!door[k].empty())
                    {
                        auto cur = door[k].front();
                        door[k].pop();

                        Q.push(cur);
                    }
                }

                // 2. 문

                if (isupper(arr[nx][ny]))
                {
                    int k = arr[nx][ny] + 32 - 'a';
                    if (!key[k])
                    {
                        door[k].push({nx, ny});
                        continue;
                    }
                }

                // 3. 문서

                if (arr[nx][ny] == '$')
                {
                    cnt++;
                }

                Q.push({nx, ny});
            }
        }

        cout << cnt << "\n";
    }
}

/*
1
5 17
*****************
.............**$*
*B*A*P*C**X*Y*.X.
*y*x*a*p**$*$**$*
*****************
cz
*/
