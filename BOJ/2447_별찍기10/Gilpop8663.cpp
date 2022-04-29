#include <bits/stdc++.h>
using namespace std;

char board[2300][2300];

// func(n, x, y) : board[x][y] to board[x+n-1][y+n-1]에 올바르게 '*'과 ' '을 넣는 함수
void func(int n, int x, int y)
{
    if (n == 1)
    {
        board[x][y] = '*';
        return;
    }
    for (int i = 0; i < 3; i++)
    {

        for (int j = 0; j < 3; j++)
        {

            if (i == 1 && j == 1)
                continue;
            func(n / 3, x + n / 3 * i, y + n / 3 * j);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        fill(board[i], board[i] + N, ' ');
    }

    func(N, 0, 0);

    for (int i = 0; i < N; i++)
        cout << board[i] << "\n";
}
