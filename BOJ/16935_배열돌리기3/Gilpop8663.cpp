#include <bits/stdc++.h>
using namespace std;

int n, m, r;

int arr[105][105];
int tmp[105][105];

void copy()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = tmp[i][j];
        }
    }
    return;
}

void first_func()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            tmp[n - i - 1][j] = arr[i][j];
        }
    }

    copy();
}

void second_func()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            tmp[i][m - j - 1] = arr[i][j];
        }
    }

    copy();
}

void third_func(int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            tmp[j][n - i - 1] = arr[i][j];
        }
    }

    // for (int i = 0; i < col; i++)
    // {
    //     for (int j = 0; j < row; j++)
    //     {
    //         arr[i][j] = tmp[i][j];
    //         cout << tmp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    n = col;
    m = row;

    copy();
}

void fifth_func()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            tmp[i][j] = arr[i][j];
        }
    }

    for (int i = 0; i < n / 2; i++)
    {
        for (int j = 0; j < m / 2; j++)
        {
            tmp[i][m / 2 + j] = arr[i][j];
        }
    }

    for (int i = 0; i < n / 2; i++)
    {
        for (int j = m / 2; j < m; j++)
        {
            tmp[n / 2 + i][j] = arr[i][j];
        }
    }

    for (int i = n / 2; i < n; i++)
    {
        for (int j = m / 2; j < m; j++)
        {
            tmp[i][j - m / 2] = arr[i][j];
        }
    }

    for (int i = n / 2; i < n; i++)
    {
        for (int j = 0; j < m / 2; j++)
        {
            tmp[i - n / 2][j] = arr[i][j];
        }
    }

    copy();
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> r;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < r; i++)
    {
        int num;
        cin >> num;

        if (num == 1)
        {
            first_func();
        }
        else if (num == 2)
        {
            second_func();
        }
        else if (num == 3)
        {
            third_func(n, m);
        }
        else if (num == 4)
        {
            third_func(n, m);
            third_func(n, m);
            third_func(n, m);
        }
        else if (num == 5)
        {
            fifth_func();
        }
        else if (num == 6)
        {
            fifth_func();
            fifth_func();
            fifth_func();
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}
