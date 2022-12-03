#include <bits/stdc++.h>
using namespace std;

int n;

int arr[105][105];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while (n--)
    {
        int x, y, d, g;
        cin >> x >> y >> d >> g;

        vector<int> v;

        v.push_back(d % 4);
        arr[y][x] = 1;

        while (g--)
        {

            int vSize = v.size();

            for (int i = vSize - 1; i >= 0; i--)
            {
                v.push_back((v[i] + 1) % 4);
            }
        }
        for (int i = 0; i < v.size(); i++)
        {
            int dir = v[i];
            if (dir == 0)
            {
                x++;
            }
            else if (dir == 1)
            {
                y--;
            }
            else if (dir == 2)
            {
                x--;
            }
            else if (dir == 3)
            {
                y++;
            }
            arr[y][x] = 1;
        }
    }

    int ans = 0;

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (!arr[i][j])
                continue;
            if (arr[i][j + 1] && arr[i + 1][j] && arr[i + 1][j + 1])
                ans++;
        }
    }

    cout << ans;
}
