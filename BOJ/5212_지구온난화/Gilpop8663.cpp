#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[12][12];
int ans[12][12];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            if (str[j] == '.')
            {
                arr[i][j] = 1;
            }
            else
            {
                arr[i][j] = 2;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (arr[i][j] == 2)
            {

                int cnt = 0;

                for (int k = 0; k < 4; k++)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                    {
                        cnt++;
                        continue;
                    }

                    if (arr[nx][ny] == 1)
                    {
                        cnt++;
                    }
                }

                if (cnt >= 3)
                {
                    ans[i][j] = 1;
                }
                else
                {
                    ans[i][j] = 2;
                }
            }
            else
            {
                ans[i][j] = 1;
            }
        }
    }

    int minX = 15, minY = 15;
    int maxX = 0, maxY = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // cout << ans[i][j] << " ";
            if (ans[i][j] == 2)
            {

                minY = min(minY, i);
                maxY = max(maxY, i);
                minX = min(minX, j);
                maxX = max(maxX, j);
            }
        }
        // cout << "\n";
    }

    for (int i = minY; i <= maxY; i++)
    {
        for (int j = minX; j <= maxX; j++)
        {
            if (ans[i][j] == 2)
            {
                cout << 'X';
            }
            else
            {
                cout << '.';
            }
        }
        cout << "\n";
    }
}
