#include <bits/stdc++.h>
using namespace std;

int n, m;

bool arr[55][55];
bool ans[55][55];

bool comp(int y, int x)
{
    int nx = x + 3;
    int ny = y + 3;

    // cout << nx << " " << ny << "\n";

    if (ny > n || nx > m)
        return false;

    return true;
}

void func(int y, int x)
{

    for (int i = y; i < y + 3; i++)
    {
        for (int j = x; j < x + 3; j++)
        {
            if (arr[i][j] == 0)
            {
                arr[i][j] = 1;
            }
            else
            {
                arr[i][j] = 0;
            }
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
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            if (str[j] == '1')
            {
                arr[i][j] = 1;
            }
            else
            {
                arr[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            if (str[j] == '1')
            {
                ans[i][j] = 1;
            }
            else
            {
                ans[i][j] = 0;
            }
        }
    }

    int num = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == ans[i][j])
                continue;

            // cout << comp(i, j) << "\n";
            if (comp(i, j) == true)
            {
                func(i, j);
                num++;

                //     for (int k = 0; k < n; k++)
                //     {
                //         for (int l = 0; l < m; l++)
                //         {

                //             cout << arr[k][l] << " ";
                //         }
                //         cout << "\n";
                //     }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            // cout << ans[i][j] << " ";
            if (arr[i][j] != ans[i][j])
            {
                cout << -1;
                return 0;
            }
        }
        // cout << "\n";
    }

    cout << num;
}