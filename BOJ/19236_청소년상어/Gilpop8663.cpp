#include <bits/stdc++.h>
using namespace std;

int result = 0;

vector<tuple<int, int, int>> fish(18); // x , y , dir

int dx[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int dy[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};

vector<vector<int>> arr(4, vector<int>(4)); // fishNum , 33은 상어 숫자

void printFishLoc()
{
    for (int i = 1; i <= 16; i++)
    {
        int x = get<0>(fish[i]);
        int y = get<1>(fish[i]);
        int dir = get<2>(fish[i]);

        cout << i << "번 물고기 :" << x << " " << y << " " << dir << "\n";
    }
    cout << "\n";
}

void printFishNum()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void moveFish(vector<tuple<int, int, int>> &info, vector<vector<int>> &board, int sharkX, int sharkY)
{
    for (int i = 1; i <= 16; i++)
    {
        int x = get<0>(info[i]);
        int y = get<1>(info[i]);
        int dir = get<2>(info[i]);

        if (board[x][y] == -1 || board[x][y] == 0)
            continue;

        // cout << i << " " << x << " " << y << " " << dir << "\n";

        while (true)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4 || (sharkX == nx && sharkY == ny))
            {
                if (dir == 8)
                {
                    dir = 1;
                }
                else
                {
                    dir++;
                }
            }
            else
            {
                break;
            }
        }

        // cout << i << " " << x << " " << y << " " << dir << "\n";

        int nx = x + dx[dir];
        int ny = y + dy[dir];

        int fishNum = board[nx][ny];

        int fishDir = get<2>(info[fishNum]);

        if (board[nx][ny] != -1)
        {

            info[i] = {nx, ny, dir};
            info[fishNum] = {x, y, fishDir};
            // cout << "현재 물고기 " << i << " " << x << " " << y << " " << dir << "\n";
            // cout << "바꿀 물고기 " << fishNum << " " << nx << " " << ny << " " << fishDir << "\n";
            swap(board[x][y], board[nx][ny]);
        }
        else
        {
            info[i] = {nx, ny, dir};
            board[nx][ny] = i;
            board[x][y] = -1;
        }

        // printFishLoc();
    }

    return;
}

void func(int sharkX, int sharkY, int sum, vector<vector<int>> &board, vector<tuple<int, int, int>> &info)
{

    vector<vector<int>> copy_board(4, vector<int>(4));
    vector<tuple<int, int, int>> copy_info(18);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            copy_board[i][j] = board[i][j];
        }
    }

    for (int i = 1; i <= 16; i++)
    {
        copy_info[i] = info[i];
    }

    //상어가 물고기 먹음
    int eatFishNum = copy_board[sharkX][sharkY];
    copy_board[sharkX][sharkY] = -1;

    //상어 이동방향 설정
    int sharkDir = get<2>(copy_info[eatFishNum]);
    copy_info[eatFishNum] = {0, 0, 0};

    sum += eatFishNum;
    if (result < sum)
    {
        result = sum;
    }

    //물고기 이동

    moveFish(copy_info, copy_board, sharkX, sharkY);

    //상어 이동

    for (int i = 1; i < 4; i++)
    {
        int nx = sharkX + dx[sharkDir] * i;
        int ny = sharkY + dy[sharkDir] * i;

        if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4)
            break;

        int fishNum = copy_board[nx][ny];

        if (fishNum == -1)
            continue;

        func(nx, ny, sum, copy_board, copy_info);
    }

    return;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 4;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            int fishNum, dir;
            cin >> fishNum >> dir;

            arr[i][j] = fishNum;

            fish[fishNum] = {i, j, dir};
        }
    }

    // cout << result << "\n";
    func(0, 0, 0, arr, fish);

    cout << result << "\n";
}