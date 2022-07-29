#include <bits/stdc++.h>

using namespace std;

int n, m;

int arr[505][505];
int tmp[505][505];

int func1(int y, int x) // 일자
{
    int sum = 0;
    int ny = y;
    int nx = x + 3;
    if (nx >= m || ny >= n || nx < 0 || ny < 0)
        return 0;

    for (int i = 0; i < 4; i++)
    {
        sum += arr[y][x + i];
    }

    return sum;
}

int func2(int y, int x) // ㄴ자
{
    int sum = 0;
    int nx = x + 1;
    int ny = y + 2;
    if (nx >= m || ny >= n || nx < 0 || ny < 0)
        return 0;

    sum = arr[y][x] + arr[y + 1][x] + arr[y + 2][x] + arr[y][x + 1];

    return sum;
}

int func3(int y, int x) // 지그재그
{
    int sum = 0;
    int nx = x + 1;
    int ny = y + 2;
    if (nx >= m || ny >= n || nx < 0 || ny < 0)
        return 0;

    sum = arr[y][x] + arr[y + 1][x] + arr[y + 1][x + 1] + arr[y + 2][x + 1];

    return sum;
}

int func4(int y, int x) // ㅗ 자
{
    int sum = 0;
    int nx = x + 2;
    int ny = y + 1;
    if (nx >= m || ny >= n || nx < 0 || ny < 0)
        return 0;

    sum = arr[y][x] + arr[y][x + 1] + arr[y + 1][x + 1] + arr[y][x + 2];

    return sum;
}

int func5(int y, int x) // 네모
{
    int sum = 0;
    int nx = x + 1;
    int ny = y + 1;
    if (nx >= m || ny >= n || nx < 0 || ny < 0)
        return 0;

    sum = arr[y][x] + arr[y][x + 1] + arr[y + 1][x] + arr[y + 1][x + 1];

    return sum;
}

int func6(int y, int x) //ㄴ 자  대칭
{
    int sum = 0;
    int nx = x - 1;
    int ny = y + 2;
    if (nx >= m || ny >= n || nx < 0 || ny < 0)
        return 0;

    sum = arr[y][x] + arr[y][x - 1] + arr[y + 1][x] + arr[y + 2][x];

    return sum;
}

int func7(int y, int x) //지그재그 대칭
{
    int sum = 0;
    int nx = x - 1;
    int ny = y + 2;
    if (nx >= m || ny >= n || nx < 0 || ny < 0)
        return 0;

    sum = arr[y][x] + arr[y + 1][x] + arr[y + 1][x - 1] + arr[y + 2][x - 1];

    return sum;
}

void rotate()
{
    swap(n, m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            tmp[i][j] = arr[m - j - 1][i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = tmp[i][j];
        }
    }
    return;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    int ans = 0;

    for (int k = 0; k < 4; k++)
    {
        if (k != 0)
        {

            rotate();
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int tmp = 0;
                tmp = max(tmp, func1(i, j));
                tmp = max(tmp, func2(i, j));
                tmp = max(tmp, func3(i, j));
                tmp = max(tmp, func4(i, j));
                tmp = max(tmp, func5(i, j));
                tmp = max(tmp, func6(i, j));
                tmp = max(tmp, func7(i, j));

                ans = max(ans, tmp);
            }
        }
    }

    cout << ans;
}