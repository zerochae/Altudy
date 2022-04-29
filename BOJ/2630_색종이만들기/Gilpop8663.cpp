#include <bits/stdc++.h>
using namespace std;

int board[130][130];
int color[2];

//모든 숫자가 같은 숫자로 이루어져 있는지 확인하는 함수
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

    if (check(x, y, z)) // 같은 숫자로 되어있다면 해당 숫자 배열을 ++ 함
    {
        color[board[x][y]]++;
        return;
    }

    int n = z / 2;
    func(x, y, n);         // 왼쪽 아래
    func(x, y + n, n);     //왼쪽 위
    func(x + n, y, n);     // 오른쪽 아래
    func(x + n, y + n, n); // 오른쪽 위
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

    for (int i = 0; i < 2; i++)
    {
        cout << color[i] << "\n";
    }
}
