#include <bits/stdc++.h>
using namespace std;

int arr[501][501];

int n;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int score = 0;

double tornado[5][5];
double copy_tornado[5][5];
double tmp_tornado[5][5];

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

void rotate()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            tmp_tornado[i][j] = copy_tornado[5 - j - 1][i];
        }
    }
    memmove(copy_tornado, tmp_tornado, sizeof(copy_tornado));
    return;
}

void move(int x, int y, int dir)
{

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            copy_tornado[i][j] = tornado[i][j];
        }
    }

    if (dir == 3)
    {
        rotate();
    }

    if (dir == 2)
    {
        rotate();
        rotate();
    }

    if (dir == 1)
    {
        rotate();
        rotate();
        rotate();
    }

    int sand = arr[x][y];
    arr[x][y] = 0;

    int total = sand;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (copy_tornado[i][j] == 99)
                continue;
            int number = (int)floor(copy_tornado[i][j] * sand);
            int nx = x + i - 2;
            int ny = y + j - 2;

            if (nx < 0 || ny < 0 || nx >= n || ny >= n)
            {
                score += number;
                total -= number;
                continue;
            }
            arr[nx][ny] += number;
            total -= number;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (copy_tornado[i][j] == 99)
            {
                int nx = x + i - 2;
                int ny = y + j - 2;

                if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                {
                    score += total;
                    continue;
                }
                arr[nx][ny] += total;
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

    tornado[0][2] = 0.02;
    tornado[1][1] = 0.10;
    tornado[1][2] = 0.07;
    tornado[1][3] = 0.01;
    tornado[2][0] = 0.05;
    tornado[2][1] = 99;
    tornado[3][1] = 0.10;
    tornado[3][2] = 0.07;
    tornado[3][3] = 0.01;
    tornado[4][2] = 0.02;

    int cen = n / 2;

    int col = cen;
    int row = cen;

    int dir = 0;

    bool isFind = 0;

    for (int i = 1; i <= n; i++)
    {

        for (int j = 0; j < i; j++)
        {

            col += dx[dir];
            row += dy[dir];
            move(col, row, dir);
            if (row == 0 && col == 0)
            {
                isFind = 1;
                break;
            }
        }
        if (isFind == 1)
            break;
        dir = (dir + 1) % 4;
        for (int j = 0; j < i; j++)
        {

            col += dx[dir];
            row += dy[dir];
            move(col, row, dir);
        }
        dir = (dir + 1) % 4;
    }

    cout << score;
}
