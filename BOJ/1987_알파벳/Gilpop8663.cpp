#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[25][25];

bool ch[30] = {0};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int ans = 0;

int func(int x, int y, int cnt)
{

    ans = max(ans, cnt);

    // cout << x << " " << y << " " << arr[x][y] << " " << cnt << "\n";

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m || ch[arr[nx][ny]] == 1)
            continue;
        ch[arr[nx][ny]] = 1;
        func(nx, ny, cnt + 1);
        ch[arr[nx][ny]] = 0;
    }

    return cnt;
}

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
            arr[i][j] = str[j] - 'A';
        }
    }

    ch[arr[0][0]] = 1;

    ans = max(ans, func(0, 0, 1));

    cout << ans;
}
