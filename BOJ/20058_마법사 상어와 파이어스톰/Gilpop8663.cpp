#include <bits/stdc++.h>
using namespace std;

int n, q;

int arr[130][130];

int copy_arr[130][130];
int tmp[130][130];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<pair<int, int>> Q;
bool ch[130][130] = {0};

void print()
{
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void rotate(int x, int y, int k)
{

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            copy_arr[i][j] = arr[x + i][y + j];
        }
    }

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            tmp[i][j] = copy_arr[k - j - 1][i];
        }
    }

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            arr[x + i][y + j] = tmp[i][j];
        }
    }

    return;
}

void melt()
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tmp[i][j] = arr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int count = 0;
            if (arr[i][j] == 0)
                continue;
            for (int k = 0; k < 4; k++)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                    continue;
                if (arr[nx][ny] <= 0)
                    continue;
                count++;
            }

            if (count < 3)
            {
                tmp[i][j]--;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = tmp[i][j];
        }
    }
}

void func(int L)
{
    int num = pow(2, L);

    for (int i = 0; i < n; i += num)
    {
        for (int j = 0; j < n; j += num)
        {
            rotate(i, j, num);
        }
    }
}

int calAns()
{
    int iceSum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            iceSum += arr[i][j];
        }
    }

    return iceSum;
}

int calLand()
{

    int landCount = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int perCount = 0;
            if (ch[i][j] == 1)
                continue;
            if (arr[i][j] > 0)
            {
                ch[i][j] = 1;
                Q.push({i, j});

                while (!Q.empty())
                {
                    auto cur = Q.front();
                    Q.pop();

                    perCount++;

                    int x = cur.first;
                    int y = cur.second;
                    for (int k = 0; k < 4; k++)
                    {
                        int nx = x + dx[k];
                        int ny = y + dy[k];

                        if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                            continue;
                        if (ch[nx][ny] == 1 || arr[nx][ny] == 0)
                            continue;
                        ch[nx][ny] = 1;
                        Q.push({nx, ny});
                    }
                }

                landCount = max(landCount, perCount);
            }
        }
    }

    return landCount;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;

    n = pow(2, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < q; i++)
    {
        int L;
        cin >> L;
        func(L);
        melt();
    }

    cout << calAns() << "\n";
    cout << calLand();
}

/*

3 1
1 2 3 4 5 6 7 8
9 10 11 12 13 14 15 16
17 18 19 20 21 22 23 24
25 26 27 28 29 30 31 32
33 34 35 36 37 38 39 40
41 42 43 44 45 46 47 48
49 50 51 52 53 54 55 56
57 58 59 60 61 62 63 64
1


3 1
1 2 3 4 5 6 7 8
9 10 11 12 13 14 15 16
17 18 19 20 21 22 23 24
25 26 27 28 29 30 31 32
33 34 35 36 37 38 39 40
41 42 43 44 45 46 47 48
49 50 51 52 53 54 55 56
57 58 59 60 61 62 63 64
2
*/