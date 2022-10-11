#include <bits/stdc++.h>
using namespace std;

int n;

int arr[22][22];

int ch[22][22];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int x, y;

    int eatFish = 0, babySize = 2;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 9)
            {
                x = i;
                y = j;
            }
        }
    }

    int ans = 0;
    while (1)
    {
        fill(&ch[0][0], &ch[21][22], -1);

        arr[x][y] = 0;
        ch[x][y] = 0;

        queue<pair<int, int>> q;
        vector<pair<int, int>> fish;

        if (eatFish >= babySize)
        {
            eatFish -= babySize;
            babySize++;
        }

        q.push({x, y});

        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];

                if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                    continue;
                if (ch[nx][ny] != -1)
                    continue;
                if (arr[nx][ny] > babySize)
                    continue;
                if (arr[nx][ny] == babySize || arr[nx][ny] == 0)
                {
                    q.push({nx, ny});
                }
                else if (arr[nx][ny] < babySize)
                {
                    fish.push_back({nx, ny});
                    q.push({nx, ny});
                }
                ch[nx][ny] = ch[cur.first][cur.second] + 1;
            }
        }

        if (fish.size() == 0)
        {
            break;
        }
        else if (fish.size() == 1)
        {
            eatFish++;
            auto tmp = fish[0];

            arr[tmp.first][tmp.second] = 9;

            x = fish[0].first;
            y = fish[0].second;
            ans += ch[x][y];
        }
        else
        {
            int minDist = 1e9;

            for (int i = 0; i < fish.size(); i++)
            {
                auto tmp = fish[i];

                minDist = min(minDist, ch[tmp.first][tmp.second]);
            }

            vector<pair<int, int>> minFish;

            for (int i = 0; i < fish.size(); i++)
            {
                auto tmp = fish[i];

                if (ch[tmp.first][tmp.second] == minDist)
                {
                    minFish.push_back(tmp);
                }
            }

            if (minFish.size() == 1)
            {
                eatFish++;
                x = minFish[0].first;
                y = minFish[0].second;
                ans += ch[x][y];
            }
            else
            {
                sort(minFish.begin(), minFish.end());
                eatFish++;
                x = minFish[0].first;
                y = minFish[0].second;
                ans += ch[x][y];
            }
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    cout << ans << "\n";
}
