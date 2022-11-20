#include <bits/stdc++.h>
using namespace std;

int n, m, t;

int arr[55][55];
int tmp[55][55];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

vector<pair<int, int>> air;

void print()
{
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    return;
}

void func(int x, int y)
{
    int amount = arr[x][y] / 5;

    if (amount <= 0)
        return;
    int count = 0;
    for (int k = 0; k < 4; k++)
    {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
            continue;
        if (arr[nx][ny] == -1)
            continue;
        count++;
        tmp[nx][ny] += amount;
    }

    arr[x][y] -= count * amount;
    return;
}

void airDown(int x, int y)
{
    int prevNum = 0;
    int nextNum = 0;
    for (int i = y; i < m; i++)
    {
        if (arr[x][i] == -1)
            continue;
        nextNum = arr[x][i];
        arr[x][i] = prevNum;
        prevNum = nextNum;
    }

    for (int i = x + 1; i < n; i++)
    {
        if (arr[i][m - 1] == -1)
            continue;
        nextNum = arr[i][m - 1];
        arr[i][m - 1] = prevNum;
        prevNum = nextNum;
    }

    for (int i = m - 2; i >= y; i--)
    {
        if (arr[n - 1][i] == -1)
            continue;
        nextNum = arr[n - 1][i];
        arr[n - 1][i] = prevNum;
        prevNum = nextNum;
    }

    for (int i = n - 2; i >= x; i--)
    {
        if (arr[i][y] == -1)
            continue;
        nextNum = arr[i][y];
        arr[i][y] = prevNum;
        prevNum = nextNum;
    }
    return;
}

void airUp(int x, int y)
{
    int prevNum = 0;
    int nextNum = 0;
    for (int i = y; i < m; i++)
    {
        if (arr[x][i] == -1)
            continue;
        nextNum = arr[x][i];
        arr[x][i] = prevNum;
        prevNum = nextNum;
    }

    for (int i = x - 1; i >= 0; i--)
    {
        if (arr[i][m - 1] == -1)
            continue;
        nextNum = arr[i][m - 1];
        arr[i][m - 1] = prevNum;
        prevNum = nextNum;
    }

    for (int i = m - 2; i >= 0; i--)
    {
        if (arr[0][i] == -1)
            continue;
        nextNum = arr[0][i];
        arr[0][i] = prevNum;
        prevNum = nextNum;
    }

    for (int i = 1; i <= x; i++)
    {
        if (arr[i][y] == -1)
            continue;
        nextNum = arr[i][y];
        arr[i][y] = prevNum;
        prevNum = nextNum;
    }
    return;
}

void sumFunc()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][j] += tmp[i][j];
            tmp[i][j] = 0;
        }
    }
    return;
}

int ansFunc()
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] > 0)
            {
                ans += arr[i][j];
            }
        }
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> t;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == -1)
            {
                air.push_back({i, j});
            }
        }
    }

    // print();
    while (t--)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] > 0)
                {
                    func(i, j);
                }
            }
        }
        sumFunc();
        airUp(air[0].first, air[0].second);
        airDown(air[1].first, air[1].second);
    }
    int ans = ansFunc();
    cout << ans;
    // print();
}

/*
3 3 1
5 0 0
0 0 0
0 0 0

3 3 1
0 0 0
0 46 0
0 0 0

3 3 1
0 30 7
-1 10 0
-1 0 20
*/