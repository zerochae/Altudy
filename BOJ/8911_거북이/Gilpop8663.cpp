#include <bits/stdc++.h>
using namespace std;

int t;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;

    while (t--)
    {
        string str;

        cin >> str;

        int n = str.size();
        int dir = 1; // 북쪽

        int maxY = 0, minY = 0, maxX = 0, minX = 0;

        pair<int, int> cur = {0, 0};

        for (int i = 0; i < n; i++)
        {
            if (str[i] == 'F')
            {
                cur.first += dx[dir];
                cur.second += dy[dir];
            }
            else if (str[i] == 'L')
            {
                dir = (dir + 1) % 4;
            }
            else if (str[i] == 'R')
            {
                dir = (dir + 3) % 4;
            }
            else if (str[i] == 'B')
            {
                int back = (dir + 2) % 4;
                cur.first += dx[back];
                cur.second += dy[back];
            }

            // cout << cur.first << " " << cur.second << "\n";
            maxX = max(maxX, cur.first);
            maxY = max(maxY, cur.second);
            minX = min(minX, cur.first);
            minY = min(minY, cur.second);
        }

        // cout << maxX << " " << minX << " " << maxY << " " << minY << "\n";
        int ans = (maxX - minX) * (maxY - minY);
        cout << ans << "\n";
    }
}