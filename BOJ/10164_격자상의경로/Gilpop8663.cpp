#include <bits/stdc++.h>
using namespace std;

int n, m, k;

int arr[20][20];

queue<tuple<int, int, bool>> q;

int dx[2] = {1, 0};
int dy[2] = {0, 1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int number = i * m + j + 1;
            // cout << number << "\n";
        }
    }

    if (k == 0)
    {
        q.push({0, 0, 1});
    }
    else
    {
        q.push({0, 0, 0});
    }

    int ans = 0;
    while (!q.empty())
    {
        tuple<int, int, bool> cur = q.front();
        q.pop();

        int x = get<0>(cur);
        int y = get<1>(cur);
        bool isFind = get<2>(cur);

        int number = x * m + y + 1;
        if (number == k)
        {
            isFind = 1;
        }
        // cout << x << " " << y << " " << isFind << "\n";

        if (number > k && isFind == 0)
            continue;
        if (x == n - 1 && y == m - 1 && isFind == 1)
        {
            ans++;
            continue;
        }

        for (int i = 0; i < 2; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= n || ny >= m)
                continue;
            q.push({nx, ny, isFind});
        }
    }

    cout << ans;
}
