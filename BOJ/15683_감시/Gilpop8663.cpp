#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m;

int board1[10][10]; // 최초에 입력받은 board를 저장할 변수
int board2[10][10]; // 사각 지대의 개수를 세기 위해 사용할 변수
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1}; // 남쪽 , 동쪽 , 북쪽 , 서쪽 순서

vector<pair<int, int>> cctv; // cctv의 좌표를 저장할 변수;

queue<tuple<int, int, int>> q;

bool OOB(int a, int b)
{ // Out of Bounds 확인
    return a < 0 || a >= n || b < 0 || b >= m;
}

//(x,y) 에서 dir 방향으로 진행하면서 벽을 만날 때 까지 지나치는 모든 빈칸을 7로 바꿔버림
void upd(int x, int y, int dir)
{
    dir %= 4;
    while (1)
    {
        x += dx[dir];
        y += dy[dir];
        if (OOB(x, y) || board2[x][y] == 6) // 범위를 벗어났거나 벽을 만나면 함수를 탈출
            return;
        if (board2[x][y] != 0)
            continue; // 해당 칸이 빈칸이 아닐경우 ( = cctv가 있을 경우) 넘어감
        board2[x][y] = 7;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int mn = 0; //사각 지대의 최소 크기 (=답)

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board1[i][j];
            if (board1[i][j] < 6 && board1[i][j] > 0)
            {
                cctv.push_back({i, j});
            }
            if (board1[i][j] == 0)
                mn++;
        }
    }

    // cctv가 3개 있을 때 4의 3승을 4진법으로 표현하였을 때 잘 나오는 것을 알 수 있음.
    //  for (int tmp = 0; tmp < 64; tmp++)
    //  {
    //      int brute = tmp;
    //      for (int i = 0; i < 3; i++)
    //      {
    //          cout << brute % 4;
    //          brute /= 4;
    //      }
    //      cout << "\n";
    //  }

    // 1 << (2*cctv.size())는 4의 cctv.size()승을 의미.
    for (int tmp = 0; tmp < (1 << (2 * cctv.size())); tmp++)
    { // tmp를 4진법으로 뒀을 때 각 자리수를 cctv의 방향으로 생각할 것이다. 0은 북 , 1은 동 , 2 남 ,3 서
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                board2[i][j] = board1[i][j];
            }
        }
        int brute = tmp;
        for (int i = 0; i < cctv.size(); i++)
        {
            int dir = brute % 4;
            brute /= 4;
            // int x = cctv[i].X;
            // int y = cctv[i].Y; // tie(x,y) = cctv[i]; 로 쓰면 1줄로 줄일 수 있음
            int x, y;
            tie(x, y) = cctv[i];
            if (board1[x][y] == 1)
            {
                upd(x, y, dir);
            }
            else if (board1[x][y] == 2)
            {
                upd(x, y, dir);
                upd(x, y, dir + 2);
            }
            else if (board1[x][y] == 3)
            {
                upd(x, y, dir);
                upd(x, y, dir + 1);
            }
            else if (board1[x][y] == 4)
            {
                upd(x, y, dir);
                upd(x, y, dir + 1);
                upd(x, y, dir + 2);
            }
            else // board1[x][y] == 5
            {
                upd(x, y, dir);
                upd(x, y, dir + 1);
                upd(x, y, dir + 2);
                upd(x, y, dir + 3);
            }
        }

        int val = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                val += (board2[i][j] == 0);
        mn = min(mn, val);
    }
    cout << mn;
}
