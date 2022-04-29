#include <bits/stdc++.h>
using namespace std;

char board[3072][3072 * 2 - 1];

void fill_star(const int &x, const int &y)
{
    board[x][y] = '*';                                    // 맨 위
    board[x + 1][y - 1] = '*', board[x + 1][y + 1] = '*'; // 2번째

    for (int i = y - 2; i <= y + 2; ++i) // 3번째
    {
        board[x + 2][i] = '*';
    }
}

void func(int s, int x, int y)
{
    if (s == 3)
    {
        fill_star(x, y);
        return;
    }
    int ns = s / 2;
    func(ns, x, y);           //위 삼각형
    func(ns, x + ns, y - ns); // 좌 삼각형
    func(ns, x + ns, y + ns); // 우 삼각형
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    func(N, 0, N - 1);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N * 2 - 1; j++)
        {
            if (board[i][j] == '*')
                cout << '*';
            else
                cout << ' ';
        }
        cout << "\n";
    }
}
