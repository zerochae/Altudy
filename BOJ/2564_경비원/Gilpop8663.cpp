#include <bits/stdc++.h>
using namespace std;

int n, m, k;

pair<int, int> dist[10005];

pair<int, int> me;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int ans = 0;
    cin >> m >> n >> k;

    for (int i = 0; i < k; i++)
    {
        cin >> dist[i].first >> dist[i].second;
    }

    cin >> me.first >> me.second;

    for (int i = 0; i < k; i++)
    {
        int meDir = me.first;
        int y = me.second;
        int dir = dist[i].first;
        int ny = dist[i].second;

        cout << meDir << " " << y << " " << dir << " " << ny << "\n";

        if (meDir == dir)
        {
            ans += abs(me.second - ny);
        }
        else if (meDir != dir)
        {

            if (meDir == 1)
            {
                if (dir == 2)
                {
                    ans += n + min(y + ny, m - y + m - ny);
                }
                else if (dir == 3)
                {
                    ans += y + ny;
                }
                else if (dir == 4)
                {
                    ans += m - y + y;
                }
            }
            else if (meDir == 2)
            {
                if (dir == 1)
                {
                    ans += n + min(y + ny, m - y + m - ny);
                }
                else if (dir == 3)
                {
                    ans += y + n - ny;
                }
                else if (dir == 4)
                {
                    ans += m - y + n - ny;
                }
            }
            else if (meDir == 3)
            {
                if (dir == 1)
                {
                    ans += y + ny;
                }
                else if (dir == 2)
                {
                    ans += n - y + ny;
                }
                else if (dir == 4)
                {
                    ans += m + min(y + ny, n - y + n - ny);
                }
            }
            else if (meDir == 4)
            {
                if (dir == 1)
                {
                    ans += y + m - ny;
                }
                else if (dir == 2)
                {
                    ans += n - y + m - ny;
                }
                else if (dir == 3)
                {
                    ans += m + min(y + ny, n - y + n - ny);
                }
            }
        }
    }
    cout << ans;
}
