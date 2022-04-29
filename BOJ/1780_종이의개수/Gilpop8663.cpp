#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int board[2200][2200]; // 3의 7승의 범위

int cnt[3]; //-1,0,1로 이루어진 배열

//해당 종이 내부에 같은 숫자로만 이루어졌는지 확인하는 함수
bool check(int x, int y, int n)
{
    for (int i = x; i < x + n; i++)
    {
        for (int j = y; j < y + n; j++)
        {
            if (board[x][y] != board[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

void func(int x, int y, int z)
{
    if (check(x, y, z)) // 모두 같은 숫자면 종이 개수에 추가함
    {
        cnt[board[x][y] + 1]++;
        return;
    }
    int n = z / 3; // 9개로 쪼개줌
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            func(x + i * n, y + j * n, n);
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
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }
    func(0, 0, N);
    for (int i = 0; i < 3; i++)
    {
        cout << cnt[i] << "\n";
    }
}
