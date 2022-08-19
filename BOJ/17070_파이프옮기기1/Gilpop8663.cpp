#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[20][20];
int ans = 0;

int dx[3] = {0, 1, 1};
int dy[3] = {1, 1, 0};

void func(int x, int y, int dir)
{
    if (x == n - 1 && y == n - 1)
    {
        ans++;
        return;
    }

    for (int i = 0; i < 3; i++) // 0 은 가로 , 1은 대각선 , 2는 세로
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= n || ny >= n || nx < 0 || ny < 0 || arr[nx][ny] == 1)
            continue;
        if (i == 1)
        {
            if (arr[nx - 1][ny] == 1 || arr[nx][ny - 1] == 1)
                continue;
        }
        if (dir == 0 && i == 2)
            continue;
        if (dir == 2 && i == 0)
            continue;
        func(nx, ny, i);
    }
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

    func(0, 1, 0);

    cout << ans;
}