#include <bits/stdc++.h>
using namespace std;

int t;
int n;

int arr[11][11];
int arr2[11][11];
int ch[11][11];

int ans = 9999999;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void func(int k, int sum)
{

    if (sum > ans)
    {
        return;
    }

    if (k == 3)
    {
        ans = min(ans, sum);
        return;
    }

    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < n - 1; j++)
        {
            bool isFind = 0;
            if (ch[i][j] == 1 || arr2[i][j] < 0)
                continue;
            for (int k = 0; k < 4; k++)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if (ch[nx][ny] == 1)
                {
                    isFind = 1;
                    continue;
                }
            }

            if (isFind == 1)
                continue;

            for (int k = 0; k < 4; k++)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];

                ch[nx][ny] = 1;
            }
            ch[i][j] = 1;

            func(k + 1, sum + arr2[i][j]);

            ch[i][j] = 0;
            for (int k = 0; k < 4; k++)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];

                ch[nx][ny] = 0;
            }
        }
    }
    return;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < n - 1; j++)
        {

            int sum = arr[i][j];
            for (int k = 0; k < 4; k++)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];

                sum += arr[nx][ny];
            }
            arr2[i][j] = sum;
            // cout << arr2[i][j] << " ";
        }
        // cout << "\n";
    }

    func(0, 0);

    cout << ans << "\n";
}
