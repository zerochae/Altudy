#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[500][500]; // 0은 빈 공간 , 1은 양 ,2은 늑대,3은 울타리

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    bool isPos = 0;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;

        for (int j = 0; j < m; j++)
        {
            if (str[j] == 'S')
            {
                arr[i][j] = 1;
            }
            else if (str[j] == 'W')
            {
                arr[i][j] = 2;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (isPos == 1)
            break;
        for (int j = 0; j < m; j++)
        {
            if (isPos == 1)
                break;

            if (arr[i][j] == 1)
            {

                for (int k = 0; k < 4; k++)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if (nx < 0 || ny < 0 || nx >= n || ny > m)
                        continue;
                    if (arr[nx][ny] == 2)
                    {
                        isPos = 1;
                        break;
                    }
                }
            }
        }
    }

    if (isPos == 1)
    {
        cout << 0;
        return 0;
    }

    cout << 1 << "\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 2 || arr[i][j] == 1)
            {
                for (int k = 0; k < 4; k++)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if (nx < 0 || ny < 0 || nx >= n || ny > m || arr[nx][ny] != 0)
                        continue;
                    arr[nx][ny] = 3;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                cout << ".";
            }
            else if (arr[i][j] == 1)
            {
                cout << "S";
            }
            else if (arr[i][j] == 2)
            {
                cout << "W";
            }
            else if (arr[i][j] == 3)
            {
                cout << "D";
            }
        }
        cout << "\n";
    }

    // . 을 모두 D로 바꾸어도 정답임
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         if (arr[i][j] == 0)
    //         {
    //             cout << "D";
    //         }
    //         else if (arr[i][j] == 1)
    //         {
    //             cout << "S";
    //         }
    //         else if (arr[i][j] == 2)
    //         {
    //             cout << "W";
    //         }
    //     }
    //     cout << "\n";
    // }
}
