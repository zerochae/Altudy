#include <bits/stdc++.h>
using namespace std;

int arr[30][30];
bool ch[30][30];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n;

queue<pair<int, int>> q;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    vector<int> ans;

    int house = 0;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;

        for (int j = 0; j < n; j++)
        {
            arr[i][j] = str[j] - '0';
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (ch[i][j] == 1)
                continue;
            if (arr[i][j] == 1)
            {
                q.push({i, j});
                ch[i][j] = 1;
                house++;
            }

            int cnt = 0;

            while (!q.empty())
            {
                pair<int, int> cur = q.front();
                q.pop();

                cnt++;

                int x = cur.first;
                int y = cur.second;

                for (int k = 0; k < 4; k++)
                {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (nx < 0 || ny < 0 || nx >= n || ny >= n || arr[nx][ny] == 0)
                        continue;
                    if (ch[nx][ny] == 1)
                        continue;
                    q.push({nx, ny});
                    ch[nx][ny] = 1;
                }
            }
            if (cnt > 0)
            {
                ans.push_back(cnt);
            }
        }
    }

    sort(ans.begin(), ans.end());

    cout << house << "\n";

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "\n";
    }
}
