#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m, h;

bool ladder[35][35];

vector<pair<int, int>> coords; //고를 수 있는 사다리를 저장한 벡터

bool check()
{
    for (int j = 1; j <= n; j++)
    {
        int cur = j;
        for (int i = 1; i <= h; i++)
        {
            if (ladder[i][cur - 1])
                cur--;
            else if (ladder[i][cur])
                cur++;
        }
        if (cur != j)
            return false;
    }
    return true;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> h;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        ladder[a][b] = 1;
    }

    for (int i = 1; i <= h; i++)
    {

        for (int j = 1; j < n; j++)
        {
            if (ladder[i][j - 1] || ladder[i][j] || ladder[i][j + 1])
                continue;
            coords.push_back({i, j});
        }
    }

    if (check())
    {
        cout << 0;
        return 0;
    }

    int ans = 1e9;
    int sz = coords.size();

    for (int i = 0; i < sz; i++)
    {
        ladder[coords[i].X][coords[i].Y] = true;
        if (check())
            ans = min(ans, 1);
        for (int j = i + 1; j < sz; j++)
        {
            ladder[coords[j].X][coords[j].Y] = true;
            if (check())
                ans = min(ans, 2);
            for (int k = j + 1; k < sz; k++)
            {
                ladder[coords[k].X][coords[k].Y] = true;
                if (check())
                    ans = min(ans, 3);
                ladder[coords[k].X][coords[k].Y] = false;
            }
            ladder[coords[j].X][coords[j].Y] = false;
        }
        ladder[coords[i].X][coords[i].Y] = false;
    }
    if (ans == 1e9)
        ans = -1;

    cout << ans;
}
