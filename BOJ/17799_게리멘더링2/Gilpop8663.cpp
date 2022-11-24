#include <bits/stdc++.h>
using namespace std;

int n;

int arr[22][22];
int ch[22][22];

int ans = 1e9;

void district(int x, int y, int d1, int d2, int total)
{
    int populations[5] = {0};
    for (int i = 0; i <= d1; i++)
    {
        ch[x + i][y - i] = 5;
        ch[x + d2 + i][y + d2 - i] = 5;
    }

    for (int i = 0; i <= d2; i++)
    {
        ch[x + i][y + i] = 5;
        ch[x + d1 + i][y - d1 + i] = 5;
    }

    for (int i = 1; i < x + d1; ++i)
    {
        for (int j = 1; j <= y; ++j)
        {
            if (ch[i][j] == 5)
                break;
            ch[i][j] = 1;
            populations[0] += arr[i][j];
        }
    }

    // 2
    for (int i = 1; i <= x + d2; ++i)
    {
        for (int j = n; j >= y + 1; --j)
        {
            if (ch[i][j] == 5)
                break;
            ch[i][j] = 2;
            populations[1] += arr[i][j];
        }
    }
    // 3
    for (int i = n; i >= x + d1; --i)
    {
        for (int j = 1; j < y - d1 + d2; ++j)
        {
            if (ch[i][j] == 5)
                break;
            ch[i][j] = 3;
            populations[2] += arr[i][j];
        }
    }
    // 4
    for (int i = n; i > x + d2; --i)
    {
        for (int j = n; j >= y - d1 + d2; --j)
        {
            if (ch[i][j] == 5)
                break;
            ch[i][j] = 4;
            populations[3] += arr[i][j];
        }
    }

    populations[4] = total - (populations[0] + populations[1] + populations[2] + populations[3]);

    sort(populations, populations + 5);
    ans = min(ans, populations[4] - populations[0]);

    return;
}

bool check(int x, int y, int d1, int d2)
{
    if (x + d1 > n || y - d1 < 1)
        return false;
    if (x + d2 > n || y + d2 > n)
        return false;
    if (x + d1 + d2 > n || y - d1 + d2 > n)
        return false;

    return true;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int total = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
            total += arr[i][j];
        }
    }

    for (int x = 1; x <= n - 2; x++)
    {
        for (int y = 2; y <= n - 1; y++)
        {
            for (int d1 = 1; d1 <= n - x - 1 && d1 <= y - 1; d1++)
            {
                for (int d2 = 1; d2 <= n - x - 1 && d2 <= n - y; d2++)
                {
                    if (check(x, y, d1, d2))
                    {
                        fill(&ch[0][0], &ch[21][22], 0);
                        district(x, y, d1, d2, total);
                    }
                }
            }
        }
    }
    cout << ans;
}
