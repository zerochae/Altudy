#include <bits/stdc++.h>
using namespace std;

int arr[6][6];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

set<string> ans;

queue<tuple<int, int, string>> q;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            string str;
            q.push({i, j, str});

            while (!q.empty())
            {
                tuple<int, int, string> cur = q.front();
                q.pop();

                int x = get<0>(cur);
                int y = get<1>(cur);
                string str = get<2>(cur);

                str += arr[x][y] + '0';

                if (str.size() == 6)
                {
                    // cout << str << "\n";
                    ans.insert(str);
                    continue;
                }

                for (int k = 0; k < 4; k++)
                {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5)
                        continue;
                    q.push({nx, ny, str});
                }
            }
        }
    }

    cout << ans.size() << "\n";
}
