#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n;
int board1[22][22]; // 보드를 저장할 변수
int board2[22][22]; // 보드를 저장할 변수


void shift_row(){
    
}

void rotate() // 90도 회전하는 함수 4방향으로 기울이는 대신 판을 회전시킴
{
    int tmp[22][22];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            tmp[i][j] = board2[i][j];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board2[i][j] = tmp[n - 1 - j][i]; // 가로 세로 변경
        }
    }
}

void moved(int dir)
{
    while (dir--) // dir 만큼 회전함 1이면 90도 2면 180도 3이면 270도
        rotate();
    for (int i = 0; i < n; i++)
    {
        int tilted[22] = {};
        int idx = 0;
        for (int j = 0; j < n; j++)
        {

            if (board2[i][j] == 0) // 0이면 건너뜀
                continue;
            if (tilted[idx] == 0) // tilted[idx]가 0이라면 board2[i][j]로 밀어넣음
            {
                tilted[idx] = board2[i][j];
            }
            else if (tilted[idx] == board2[i][j]) // 같은 수라면 *2를 해주고 idx ++
            {
                tilted[idx++] *= 2;
            }
            else
            {
                tilted[++idx] = board2[i][j]; // 이미 숫자가 있다면 idx++ 해준 뒤 변수 저장
            }
        }

        for (int j = 0; j < n; j++)
        {
            board2[i][j] = tilted[j]; // 변수 저장한 것으로 줄 변경
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board1[i][j];

    int mx = 0;
    for (int tmp = 0; tmp < 1024; tmp++) // 4의 5승 (4가지 방향 5번 시도)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                board2[i][j] = board1[i][j];
            }
        }
        int brute = tmp;            // 1024번의 시도
        for (int i = 0; i < 5; i++) // 5번의 시도
        {
            int dir = brute % 4; // 4가지 방향
            brute /= 4;          // 4진법의 논리로 4로 나누어줌
            moved(dir);          // 판 기울이기
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                mx = max(mx, board2[i][j]); 
            }
        }
    }

    cout << mx << "\n";
}
