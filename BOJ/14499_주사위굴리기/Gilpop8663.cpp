#include <bits/stdc++.h>

using namespace std;

int N, M, X, Y, K;

int arr[25][25];

/*
    2
  4 1 3
    5
    6
*/

int dice[7]; // 위 0 ,아래 1, 왼 2 , 오른 3 , 앞 4 ,뒤 5

//  dice[1] = 윗면, dice[2] = 뒷면, dice[3] = 오른쪽면, dice[4] = 왼쪽면, dice[5] = 앞면, dice[6] = 아랫면

// [0,1,2,3,4,5];
// 동쪽으로 갈 경우
//[0,,3]
/*
    4
  1 3 2
    5
    4
*/

int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};

pair<int, int> move(int dir, int x, int y)
{
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (nx < 0 || ny < 0 || nx >= N || ny >= M)
        return {x, y};
    int dice1 = dice[1];
    int dice2 = dice[2];
    int dice3 = dice[3];
    int dice4 = dice[4];
    int dice5 = dice[5];
    int dice6 = dice[6];
    if (dir == 1) //동쪽
    {
        dice[1] = dice3;
        dice[3] = dice6;
        dice[4] = dice1;
        dice[6] = dice4;
    }
    else if (dir == 2) //서쪽
    {
        dice[1] = dice4;
        dice[6] = dice3;
        dice[4] = dice6;
        dice[3] = dice1;
    }
    else if (dir == 3) //북쪽
    {
        dice[6] = dice5;
        dice[5] = dice1;
        dice[1] = dice2;
        dice[2] = dice6;
    }
    else if (dir == 4) // 남쪽
    {
        dice[2] = dice1;
        dice[1] = dice5;
        dice[5] = dice6;
        dice[6] = dice2;
    }

    return {nx, ny};
}

// 바닥 6 , 하늘 1  , 오른쪽 3 , 왼쪽  4, 앞 2 , 뒤 5

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> X >> Y >> K;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < K; i++)
    {
        int dir;

        cin >> dir;
        int nx = X + dx[dir];
        int ny = Y + dy[dir];
        if (nx < 0 || ny < 0 || nx >= N || ny >= M)
            continue;
        auto cur = move(dir, X, Y);

        if (arr[nx][ny] == 0)
        {
            arr[nx][ny] = dice[1];
        }
        else
        {
            dice[1] = arr[nx][ny];
            arr[nx][ny] = 0;
        }

        cout << dice[6] << "\n";

        X = cur.first;
        Y = cur.second;

        // cout << X << " " << Y << "\n";
    }
}