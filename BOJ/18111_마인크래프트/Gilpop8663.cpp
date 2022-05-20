#include <bits/stdc++.h>
using namespace std;

// typedef long long ll;

using ll = long long;

int n, m, b;

int arr[505][505];

int d[65];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> b;

    int tot = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            // cout << d[arr[i][j]] << " ";
        }
    }

    int minT = 0x7fffffff; // 2^31-1;
    int maxH = 0;
    for (int h = 0; h <= 256; h++)
    {
        int build = 0;
        int remove = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int num = arr[i][j];
                if (num == h)
                    continue;
                if (num < h)
                {
                    build += (h - num);
                }
                if (num > h)
                {
                    remove += (num - h);
                }
            }
        }
        // cout << remove + b << " " << build << "\n";
        int time;
        if (remove + b >= build)
        {
            time = remove * 2 + build;
            if (minT >= time)
            {
                minT = time;
                maxH = h;
            }
        }
    }
    cout << minT << " " << maxH << " "
         << "\n";
}
