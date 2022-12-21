#include <bits/stdc++.h>
using namespace std;

int n, m, k;

struct ball
{
    int weight;
    int dir;
    int speed;
};

vector<ball> arr[55][55];
vector<ball> tmp[55][55];
struct ball tmpBall;

int sameDir[4] = {0, 2, 4, 6};
int notSameDir[4] = {1, 3, 5, 7};

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void print()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << arr[i][j].size() << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void move()
{

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            while (!tmp[i][j].empty())
            {
                tmp[i][j].pop_back();
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 0; k < arr[i][j].size(); k++)
            {

                int speed = arr[i][j][k].speed % n;
                int dir = arr[i][j][k].dir;

                int nx = i;
                int ny = j;

                while (speed--)
                {
                    nx += dx[dir];
                    ny += dy[dir];

                    if (nx == 0)
                    {
                        nx = n;
                    }
                    else if (nx == n + 1)
                    {
                        nx = 1;
                    }

                    if (ny == 0)
                    {
                        ny = n;
                    }
                    else if (ny == n + 1)
                    {
                        ny = 1;
                    }
                }

                tmp[nx][ny].push_back(arr[i][j][k]);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (tmp[i][j].size() > 1)
            {
                int wSum = 0;
                int sSum = 0;
                bool isNotSameDir = 0;
                int firstDir = tmp[i][j][0].dir % 2;
                for (int k = 0; k < tmp[i][j].size(); k++)
                {
                    if (firstDir != tmp[i][j][k].dir % 2)
                    {
                        isNotSameDir = 1;
                    }

                    sSum += tmp[i][j][k].speed;
                    wSum += tmp[i][j][k].weight;
                }

                wSum = wSum / 5;
                sSum = sSum / tmp[i][j].size();

                while (!tmp[i][j].empty())
                {
                    tmp[i][j].pop_back();
                }

                if (wSum == 0)
                    continue;

                for (int k = 0; k < 4; k++)
                {
                    tmpBall.weight = wSum;
                    tmpBall.speed = sSum;
                    if (isNotSameDir)
                    {
                        tmpBall.dir = notSameDir[k];
                    }
                    else
                    {
                        tmpBall.dir = sameDir[k];
                    }

                    tmp[i][j].push_back(tmpBall);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            arr[i][j] = tmp[i][j];
            arr[i][j] = tmp[i][j];
            arr[i][j] = tmp[i][j];
        }
    }

    return;
}

int calAns()
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (arr[i][j].size() == 0)
                continue;
            for (int k = 0; k < arr[i][j].size(); k++)
            {
                sum += arr[i][j][k].weight;
            }
        }
    }

    return sum;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    for (int i = 0; i < m; i++)
    {
        int x, y, weight, dir, speed;

        cin >> x >> y >> weight >> speed >> dir;

        tmpBall.dir = dir;
        tmpBall.weight = weight;
        tmpBall.speed = speed;
        arr[x][y].push_back(tmpBall);
    }

    while (k--)
    {
        move();
    }

    cout << calAns();
}

/*
    4 4 1
1 1 5 2 2
1 4 7 1 1
4 4 7 1 3
4 1 3 6 6

4 2 2
1 1 5 2 2
1 4 7 1 6
*/