#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m, k; //노트북의 가로 ,세로 , 스티커 개수

int note[42][42];  // 스티커를 붙힐 노트북 가로세로를 저장할 변수
int r, c;          // 스티커의 가로 세로
int paper[12][12]; // 스티커를 저장할 변수

void rotate()
{
    int tmp[12][12];                // 임시로 저장할 변수
    for (int i = 0; i < r; i++)     // 스티커의 가로
        for (int j = 0; j < c; j++) // 스티커의 세로
            tmp[i][j] = paper[i][j];

    for (int i = 0; i < c; i++) // 스티커가 회전하면 세로가 스티커의 가로가 됨
    {
        for (int j = 0; j < r; j++) // 스티커가 회전하면 가로가 스티커의 세로가 됨
        {
            paper[i][j] = tmp[r - 1 - j][i]; // 회전 시 r - 1 - j  스티커의 가로 전체 길이 - 1 - 스티커의 [j]  그리고 [i] 임
        }
    }

    swap(r, c); // c++ 의 swap  스티커의 가로 와 세로의 전역변수를  서로 바꾸어야함
}

bool pastable(int x, int y)
// note의 (x,y)에 모눈종이의 (0,0)이 올라가게 스티커를 붙일 수 있는지 판단하는 함수.
// 가능할 경우 note를 갱신한 후 true를 반환.
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (paper[i][j] == 1 && note[x + i][y + j] == 1) // (x,y)에서 시작한 note의 (x+i , y+j) 의 위치가 1이고 paper[i][j]도 1이면 false
            {
                return false;
            }
        }
    }

    for (int i = 0; i < r; i++) // 위에서 걸러졌다면 붙힐 수 있다는 의미이므로 note에 저장된 수를 붙힌걸로 고침
    {
        for (int j = 0; j < c; j++)
        {
            if (paper[i][j] == 1) // 스티커가 1일 때 note를 변경함
                note[x + i][y + j] = 1;
        }
    }
    return true;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    for (int i = 0; i < k; i++)
    {
        cin >> r >> c;
        for (int j = 0; j < r; j++)
        {
            for (int f = 0; f < c; f++)
            {
                cin >> paper[j][f];
            }
        }

        for (int j = 0; j < 4; j++)
        {
            bool is_paste = false; // 해당 스티커를 붙혔는가?
            for (int x = 0; x <= n - r; x++)
            {
                if (is_paste)
                    break;
                for (int y = 0; y <= m - c; y++)
                {
                    if (pastable(x, y)) //붙혀보기
                    {
                        is_paste = true;
                        break;
                    }
                }
            }
            if (is_paste)
                break;
            rotate(); // 회전
        }
    }

    int cnt = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cnt += note[i][j];

    cout << cnt << "\n";
}
