#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int board[64][64]; // 64까지의 범위

//해당 영상이 0 과 1 중 같은 숫자로 이루어졌는지 확인
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
    if (check(x, y, z)) // 모두 같은 숫자면 숫자 추가
    {
        cout << board[x][y];
        return;
    }
    int n = z / 2; // 2로 나누어줌

    cout << "(";
    func(x, y, n);         // 제 3 사분면
    func(x, y + n, n);     // 제 2 사분면
    func(x + n, y, n);     // 제 4 사분면
    func(x + n, y + n, n); // 제 2 사분면
    cout << ")";
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string str;

        cin >> str;
        for (int j = 0; j < N; j++)

        {
            board[i][j] = str[j] - '0';
        }
    }
    func(0, 0, N);
}
