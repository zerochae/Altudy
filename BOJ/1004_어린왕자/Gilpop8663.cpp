#include <bits/stdc++.h>
using namespace std;

int t, n;

int stX, stY, enX, enY;

int cX, cY, r;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> stX >> stY >> enX >> enY;

        cin >> n;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> cX >> cY >> r;

            int nx, mx, ny, my;

            nx = cX - r;
            mx = cX + r;
            ny = cY - r;
            my = cY + r;
            bool st = 0, en = 0;
            if (r * r > pow(cX - stX, 2) + pow(cY - stY, 2))
            {
                st = 1;
            }
            if (r * r > pow(cX - enX, 2) + pow(cY - enY, 2))
            {
                en = 1;
            }
            if (st != en)
            {
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
}
