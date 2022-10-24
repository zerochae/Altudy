#include <bits/stdc++.h>
using namespace std;

int n, m;

int g, r;

int arr[55][55];
int ableArea = 0;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int candsz;

const int EMTPY = 0;
const int GREEN = 1;
const int RED = 2;
const int FLOWER = 3;

int brute[10];

vector<pair<int, int>> cand;

int func()
{
    int cnt = 0;
    pair<int, int> tmp[55][55]; // {arrival time, color}

    queue<pair<int, int>> q;

    for (int i = 0; i < candsz; i++)
    {
        if (brute[i] == RED || brute[i] == GREEN)
        {
            tmp[cand[i].first][cand[i].second] = {0, brute[i]};
            q.push(cand[i]);
        }
    }

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        int x = cur.first;
        int y = cur.second;
        int curTime = tmp[x][y].first;
        int curColor = tmp[x][y].second;

        if (tmp[x][y].second == FLOWER)
            continue;
        for (int k = 0; k < 4; k++)
        {

            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (arr[nx][ny] == 0)
                continue;
            if (tmp[nx][ny].second == EMTPY)
            {
                tmp[nx][ny] = {curTime + 1, curColor};
                q.push({nx, ny});
            }
            else if (tmp[nx][ny].second == GREEN)
            {
                if (curColor == RED && curTime + 1 == tmp[nx][ny].first)
                {
                    cnt++;
                    tmp[nx][ny].second = FLOWER;
                }
            }
            else if (tmp[nx][ny].second == RED)
            {
                if (curColor == GREEN && curTime + 1 == tmp[nx][ny].first)
                {
                    cnt++;
                    tmp[nx][ny].second = FLOWER;
                }
            }
        }
    }

    return cnt;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    cin >> g >> r;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 2)
            {
                cand.push_back({i, j});
            }
        }
    }

    candsz = cand.size();
    fill(brute + candsz - g - r, brute + candsz - r, GREEN);
    fill(brute + candsz - r, brute + candsz, RED);

    int ans = 0;

    do
    {

        ans = max(ans, func());
    } while (next_permutation(brute, brute + candsz));

    cout << ans;
}
