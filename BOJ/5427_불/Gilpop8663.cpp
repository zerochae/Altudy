#include <bits/stdc++.h>
using namespace std;

int t, n, m;

int arr[1005][1005];
bool ch[1005][1005] = {0};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> m >> n;

        fill(&ch[0][0], &ch[1004][1005], 0);
        fill(&arr[0][0], &arr[1004][1005], 0);

        queue<pair<int, int>> fire_q;
        queue<tuple<int, int, int>> q;
        vector<pair<int, int>> fArr;
        vector<tuple<int, int, int>> hArr;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                char str;
                cin >> str;

                if (str == '.')
                {
                    arr[i][j] = 1;
                }
                else if (str == '#')
                {
                    arr[i][j] = 2;
                }
                else if (str == '@')
                {
                    arr[i][j] = 3;
                    ch[i][j] = 1;
                    q.push({i, j, 0});
                }
                else if (str == '*')
                {
                    arr[i][j] = 4;
                    fire_q.push({i, j});
                }
            }
        }

        int ans = 0;
        bool isFind = 0;
        while (1)
        {

            while (!fire_q.empty())
            {
                auto cur = fire_q.front();
                fire_q.pop();

                int x = cur.first;
                int y = cur.second;

                for (int i = 0; i < 4; i++)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx < 0 || nx < 0 || nx >= n || ny >= m)
                        continue;
                    if (ch[nx][ny] == 1)
                        continue;
                    if (arr[nx][ny] == 1)
                    {
                        ch[nx][ny] = 1;
                        arr[nx][ny] = 4;
                        fArr.push_back({nx, ny});
                    }
                }
            }

            for (auto ass : fArr)
            {
                fire_q.push(ass);
            }

            fArr.clear();

            while (!q.empty())
            {
                auto cur = q.front();
                q.pop();

                int x = get<0>(cur);
                int y = get<1>(cur);
                int cnt = get<2>(cur);
                for (int i = 0; i < 4; i++)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                    {
                        isFind = 1;
                        ans = cnt + 1;
                        break;
                    }
                    if (ch[nx][ny] == 1)
                        continue;

                    if (arr[nx][ny] == 1)
                    {
                        ch[nx][ny] = 1;
                        hArr.push_back({nx, ny, cnt + 1});
                    }
                }
            }

            for (auto ass : hArr)
            {
                q.push(ass);
            }
            hArr.clear();

            if (isFind == 1 || q.empty())
            {

                break;
            }
        }

        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < m; j++)
        //     {
        //         cout << arr[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        if (ans == 0)
        {
            cout << "IMPOSSIBLE"
                 << "\n";
        }
        else
        {
            cout << ans << "\n";
        }
    }
}
