#include <bits/stdc++.h>
using namespace std;

int n, m, k;

int arr[22][22];

int dice[6] = {1, 6, 3, 2, 4, 5}; // 위 ,아래 , 동,북,서,남
int tmp[6];                       // 위 ,아래 , 동,북,서,남

int dx[4] = {1, 0, -1, 0}; // 남 동 북 서
int dy[4] = {0, 1, 0, -1};

/*
반시계
남 ->서 0 3
동 -> 남 1 0

*/

queue<pair<int, int>> q;
bool ch[22][22] = {0};

int changeDir(int dir)
{
    if (dir == 0)
    {
        return 2;
    }
    if (dir == 1)
    {
        return 3;
    }
    if (dir == 2)
    {
        return 0;
    }
    if (dir == 3)
    {
        return 1;
    }
    return 0;
}

int rotate(int dir)
{
    if (dir == 0)
    {
        return 3;
    }
    return dir - 1;
}
int rotateReverse(int dir)
{

    return (dir + 1) % 4;
}

int getDirection(int bottomScore, int arrivalScore, int dir)
{
    if (bottomScore > arrivalScore)
    {
        return rotate(dir);
    }
    if (bottomScore < arrivalScore)
    {
        return rotateReverse(dir);
    }
    return dir;
}

tuple<int, int, int> move(int x, int y, int dir)
{
    int nx = x + dx[dir];
    int ny = y + dy[dir];

    if (nx < 1 || ny < 1 || nx > n || ny > m)
    {
        int newDir = changeDir(dir);
        return {x + dx[newDir], y + dy[newDir], newDir};
    }
    return {nx, ny, dir};
}

void changeDice(int dir)
{
    // int dice[6] = {1, 6, 3, 2, 4, 5}; 위 ,아래 , 동,북,서,남
    //                                   0   1      2 3  4  5

    if (dir == 0) // 아래로 굴러갔을 때
    {
        tmp[0] = dice[3]; // 위는 북 // 위
        tmp[1] = dice[5]; // 밑은 남 // 아래
        tmp[2] = dice[2]; // 동은 동 // 동
        tmp[3] = dice[1]; //  북은 밑 // 북
        tmp[4] = dice[4]; // 서는 서 // 서
        tmp[5] = dice[0]; // 남은 위 // 남
    }
    else if (dir == 1) // 오른쪽으로 굴러갔을 때
    {
        tmp[0] = dice[4]; // 위는 서     // 위
        tmp[1] = dice[2]; // 아래는 동          // 아래
        tmp[2] = dice[0]; // 동은 위            // 동
        tmp[3] = dice[3]; // 북은 북            // 북
        tmp[4] = dice[1]; // 서는 밑           // 서
        tmp[5] = dice[5]; // 남은 남 //  남
    }
    else if (dir == 2) // 위로 굴러갔을 때
    {
        tmp[0] = dice[5]; // 위
        tmp[1] = dice[3]; // 아래
        tmp[2] = dice[2];
        tmp[3] = dice[0];
        tmp[4] = dice[4];
        tmp[5] = dice[1];
    }
    else if (dir == 3) // 왼쪽으로 굴러갔을 때
    {
        tmp[0] = dice[2]; // 위는
        tmp[1] = dice[4];
        tmp[2] = dice[1];
        tmp[3] = dice[3];
        tmp[4] = dice[0];
        tmp[5] = dice[5];
    }

    for (int i = 0; i < 6; i++)
    {
        dice[i] = tmp[i];
    }

    return;
}

int calculateScore(int x, int y)
{

    int count = 0;
    fill(&ch[0][0], &ch[21][22], 0);
    ch[x][y] = 1;
    q.push({x, y});

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        count += 1;
        int curX = cur.first;
        int curY = cur.second;

        for (int i = 0; i < 4; i++)
        {
            int nx = curX + dx[i];
            int ny = curY + dy[i];
            if (nx < 1 || ny < 1 || nx > n || ny > m)
                continue;
            if (ch[nx][ny] == 1 || arr[nx][ny] != arr[x][y])
                continue;
            ch[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
    return count * arr[x][y];
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        }
    }

    int ans = 0;

    int x = 1, y = 1;
    int dir = 1;

    while (k--)
    {

        auto cur = move(x, y, dir);

        x = get<0>(cur);
        y = get<1>(cur);
        int nDir = get<2>(cur);

        changeDice(nDir);

        ans += calculateScore(x, y);

        dir = getDirection(dice[1], arr[x][y], nDir);
    }

    cout << ans;
}
