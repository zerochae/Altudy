#include <bits/stdc++.h>
using namespace std;

int n;

char board[55][55];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int check(int x, int y)
{
    int A = 0;
    int num = 1;
    for (int i = 0; i < n; i++)
    {
        if (board[x][i] == board[x][i + 1])
        {
            num++;
        }
        else
        {
            A = max(A, num);
            num = 1;
        }
    }

    num = 1;

    for (int i = 0; i < n; i++)
    {
        if (board[i][y] == board[i + 1][y])
        {
            num++;
        }
        else
        {
            A = max(A, num);
            num = 1;
        }
    }

    // cout << A << "\n";

    return A;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;

        for (int j = 0; j < n; j++)
        {
            board[i][j] = str[j];
            // cout << board[i][j] << " ";
        }
        // cout << "\n";
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans = max(ans, check(i, j));

            for (int k = 0; k < 4; k++)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                    continue;
                swap(board[i][j], board[nx][ny]);
                ans = max(ans, check(nx, ny));
                swap(board[i][j], board[nx][ny]);
            }
        }
    }

    cout << ans;
}
