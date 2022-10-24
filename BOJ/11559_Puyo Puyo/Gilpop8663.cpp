#include <bits/stdc++.h>
using namespace std;

char arr[13][7];
queue<pair<int, int>> q;
bool ch[13][7] = {0};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void downPuyo()
{
    for (int j = 0; j < 6; j++)
    {
        for (int i = 11; i >= 0; i--)
        {
            if (arr[i][j] == '.')
            {

                for (int k = i; k >= 0; k--)
                {
                    if (arr[k][j] != '.')
                    {
                        arr[i][j] = arr[k][j];
                        arr[k][j] = '.';
                        break;
                    }
                }
            }
        }
    }
}

void print()
{
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 6; j++)
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

    int n = 12;
    int m = 6;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = str[j];
        }
    }

    bool isStop = 0;

    int ans = 0;

    while (!isStop)
    {
        fill(&ch[0][0], &ch[12][7], 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (ch[i][j] == 1)
                    continue;
                if (arr[i][j] != '.')
                {
                    ch[i][j] = 1;
                    q.push({i, j});
                }
                vector<pair<int, int>> tmp;
                int cnt = 0;

                while (!q.empty())
                {
                    auto cur = q.front();
                    q.pop();
                    int x = cur.first;
                    int y = cur.second;
                    char curColor = arr[x][y];

                    cnt++;
                    tmp.push_back({x, y});

                    for (int k = 0; k < 4; k++)
                    {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                            continue;
                        if (ch[nx][ny] == 1)
                            continue;
                        if (curColor != arr[nx][ny])
                            continue;
                        ch[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }

                if (cnt > 3)
                {

                    isStop = 1;
                    for (int k = 0; k < tmp.size(); k++)
                    {
                        auto cur = tmp[k];
                        arr[cur.first][cur.second] = '.';
                    }
                }
            }
        }

        if (isStop == 0)
        {
            isStop = 1;
            break;
        }
        else if (isStop == 1)
        {
            isStop = 0;
        }
        ans++;

        downPuyo();
        // cout << "\n";
        // print();
        // cout << "\n";
    }

    cout << ans << "\n";
}
