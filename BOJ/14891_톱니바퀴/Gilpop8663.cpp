#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[6][9];

void func(int num, int k)
{
    int tmp[8];
    if (k == 1)
    {
        for (int i = 1; i < 8; i++)
        {
            tmp[i] = arr[num][i - 1];
        }
        tmp[0] = arr[num][7];

        for (int i = 0; i < 8; i++)
        {
            arr[num][i] = tmp[i];
        }
    }
    else if (k == -1)
    {
        for (int i = 0; i < 7; i++)
        {
            tmp[i] = arr[num][i + 1];
        }
        tmp[7] = arr[num][0];

        for (int i = 0; i < 8; i++)
        {
            arr[num][i] = tmp[i];
        }
    }

    return;
}

void funcK(int num, int k)
{
    int dir[6] = {0};
    bool ch[6] = {0};

    ch[num] = 1;
    dir[num] = k;
    for (int i = num; i <= 3; i++)
    {
        if (arr[i][2] != arr[i + 1][6])
        {
            ch[i + 1] = 1;
            if (dir[i] == 1)
            {
                dir[i + 1] = -1;
            }
            else
            {
                dir[i + 1] = 1;
            }
        }
        else
        {
            break;
        }
    }
    for (int i = num; i > 1; i--)
    {
        if (arr[i][6] != arr[i - 1][2])
        {
            ch[i - 1] = 1;
            if (dir[i] == 1)
            {
                dir[i - 1] = -1;
            }
            else
            {
                dir[i - 1] = 1;
            }
        }
        else
        {
            break;
        }
    }

    for (int i = 1; i <= 4; i++)
    {
        if (ch[i] == 1)
        {
            func(i, dir[i]);
        }
    }
    return;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1; i <= 4; i++)
    {
        string str;
        cin >> str;

        for (int j = 0; j < 8; j++)
        {
            arr[i][j] = str[j] - '0';
        }
    }

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int num, dir;
        cin >> num >> dir;

        funcK(num, dir);
    }

    int ans = 0;
    for (int i = 1; i <= 4; i++)
    {
        if (arr[i][0] == 1)
        {
            ans += pow(2, i - 1);
        }
    }

    // for (int i = 1; i <= 4; i++)
    // {

    //     for (int j = 0; j < 8; j++)
    //     {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    cout << ans;
}
