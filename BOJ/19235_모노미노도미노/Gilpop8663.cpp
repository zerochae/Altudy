#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g(6, vector<int>(4)), b(6, vector<int>(4)); // g, b :  6 * 4

int score = 0;

int dx[4] = {0, 0, 0, 1};
int dy[4] = {0, 0, 1, 0};

int now = 1;

// 0 : empty , 1: full , 2: neither
int status(vector<int> &x)
{
    int cnt0 = 0;
    for (int i = 0; i < 4; i++)
    {
        if (x[i] == 0)
            cnt0++;
    }
    if (cnt0 == 4)
        return 0;
    if (cnt0 == 0)
        return 1;
    return 2;
}

void add_block(int t, int v, vector<vector<int>> &board, int row)
{
    while (true)
    {
        if (board[row][v] || board[row + dx[t]][v + dy[t]])
        {
            row--;
            break;
        }

        if (t == 3 && row == 4)
            break;
        if (row == 5)
            break;
        row++;
    }
    board[row][v] = board[row + dx[t]][v + dy[t]] = now++;
}

void add(int t, int x, vector<vector<int>> &board)
{
    // 1. 블럭을 배치
    add_block(t, x, board, 0);
    // 2. 행이 꽉 찬 경우를 처리

    while (true)
    {
        int idx = 2; // 꽉 찬 행 찾기, 0,1행은 꽉 찬 행일 수 없음
        while (idx < 6 && status(board[idx]) != 1)
            idx++;
        if (idx == 6)
            break; // 꽉 찬 행이 없을 경우
        score++;
        board[idx] = vector<int>(4);
        for (int i = idx - 1; i >= 0; i--)
        {
            for (int j = 0; j < 4; j++)
            {
                if (board[i][j] == 0)
                    continue;
                if (j != 3 && board[i][j] == board[i][j + 1]) // 2번 블럭 형태
                {
                    board[i][j] = board[i][j + 1] = 0;
                    add_block(2, j, board, i);
                }
                else if (i != 0 && board[i - 1][j] == board[i][j]) // 3번 블럭 형태
                {
                    board[i - 1][j] = board[i][j] = 0;
                    add_block(3, j, board, i - 1);
                }
                else // 1번 블럭 형태
                {
                    board[i][j] = 0;
                    add_block(1, j, board, i);
                }
            }
        }
    }
    // 3. 0행 or 1행이 비지 않은 경우 처리
    if (status(board[0]) != 0) // 0행이 비지 않은 경우 (1행도 당연히 비지 않았음)
    {
        board.pop_back();
        board.pop_back();
        board.insert(board.begin(), 2, vector<int>(4));
    }
    else if (status(board[1]) != 0) // 0행은 비었는데 1행은 비지 않은 경우
    {
        board.pop_back();
        board.insert(board.begin(), vector<int>(4));
    }
}

int n, k;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    while (n--)
    {
        now++;
        int t, x, y;
        cin >> t >> x >> y;

        if (t == 1)
        {
            add(1, y, g);
            add(1, x, b);
        }
        else if (t == 2)
        {
            add(2, y, g);
            add(3, x, b);
        }
        else
        {
            add(3, y, g);
            add(2, x, b);
        }
    }

    int cnt = 0;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cnt += (b[i][j] != 0) + (g[i][j] != 0);
        }
    }

    cout << score << "\n"
         << cnt;
}

/*
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, k;

pair<int, int> green[6][4];

pair<int, int> blue[4][6];

pair<int, int> tmp[6][6];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bluePrint()
{
    cout << "파란색 배열"
         << "\n";
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cout << blue[i][j].X << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void greenPrint()
{
    cout << "초록색 배열"
         << "\n";
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << green[i][j].X << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

bool isGreenOverlap(int t, int count, int y)
{

    for (int j = 0; j < count; j++)
    {
        if (green[j][y].X >= 1)
            return true;
        if (t == 2 && green[j][y + 1].X >= 1)
            return true;
        if (t == 3 && green[j + 1][y].X >= 1)
            return true;
    }

    return false;
}

bool isBlueOverlap(int t, int count, int x)
{

    for (int j = 0; j < count; j++)
    {
        if (blue[x][j].X >= 1)
        {
            return true;
        }
        if (t == 3 && blue[x + 1][j].X >= 1)
        {
            return true;
        }

        if (t == 2 && blue[x][j + 1].X >= 1)
        {
            return true;
        }
    }

    return false;
}

void greenArrayMove()
{

    for (int i = 4; i >= 0; i--)
    {
        for (int j = 0; j < 4; j++)
        {
            pair<int, int> tmpNum = green[i][j];
            if (tmpNum.X == 0)
                continue;

            if (green[i][j].X == 1 || green[i][j].X == 3)
            {
                for (int k = 5; k >= i; k--)
                {
                    if (green[k][j].X >= 1)
                        continue;
                    green[k][j] = tmpNum;
                    break;
                }
                green[i][j] = {0, 0};
                continue;
            }

            if (green[i][j].X == 2)
            {
                for (int k = 5; k >= i; k--)
                {
                    if (green[k][j].X >= 1 || green[k][j + 1].X >= 1)
                        continue;
                    if (isGreenOverlap(2, k, j))
                        continue;
                    green[k][j] = tmpNum;
                    green[k][j + 1] = green[i][j + 1];
                    break;
                }
                green[i][j] = {0, 0};
                green[i][j + 1] = {0, 0};
                continue;
            }
        }
    }
    return;
}

void blueArrayMove()
{
    for (int i = 4; i >= 0; i--)
    {
        for (int j = 0; j < 4; j++)
        {
            pair<int, int> tmpNum = blue[j][i];
            if (tmpNum.X == 0)
                continue;

            if (blue[j][i].X == 1 || blue[j][i].X == 2)
            {

                for (int k = 5; k >= i; k--)
                {
                    if (blue[j][k].X >= 1)
                        continue;
                    blue[j][k] = tmpNum;
                    break;
                }
                blue[i][j] = {0, 0};
                continue;
            }

            if (blue[j][i].X == 3)
            {

                for (int k = 5; k >= i; k--)
                {
                    if (blue[j][k].X >= 1 || blue[j + 1][k].X >= 1)
                        continue;
                    if (isBlueOverlap(3, k, i))
                        continue;
                    blue[j][k] = tmpNum;
                    blue[j + 1][k] = blue[j + 1][i];
                    break;
                }
                blue[j][i] = {0, 0};
                blue[j + 1][i] = {0, 0};
                continue;
            }
        }
    }
}

int greenClear()
{
    int score = 0;
    int isFind = 1;

    while (isFind == 1)
    {

        isFind = 0;
        for (int i = 5; i >= 0; i--)
        {

            bool isClear = 1;
            for (int j = 0; j < 4; j++)
            {
                if (green[i][j].X == 0)
                {
                    isClear = 0;
                    break;
                }
            }

            if (isClear == 0)
                continue;
            score++;
            for (int j = 0; j < 4; j++)
            {
                green[i][j] = {0, 0};
            }

            isFind = 1;
        }

        if (isFind == 1)
        {
            greenArrayMove();
        }
    }

    return score;
}

int blueClear()
{
    int score = 0;
    int isFind = 1;

    while (isFind == 1)
    {

        isFind = 0;
        for (int i = 5; i >= 0; i--)
        {
            bool isClear = 1;
            for (int j = 0; j < 4; j++)
            {
                if (blue[j][i].X == 0)
                {
                    isClear = 0;
                    break;
                }
            }

            if (isClear == 0)
                continue;
            score++;
            for (int j = 0; j < 4; j++)
            {
                blue[j][i] = {0, 0};
            }
            blueArrayMove();
            isFind = 1;
        }
    }

    return score;
}

void greenMove(int t, int x, int y, int idx)
{

    for (int i = 5; i >= 0; i--)
    {
        if (green[i][y].X == 1)
            continue;

        if (t == 2 && green[i][y + 1].X >= 1)
            continue;
        if (t == 3 && green[i + 1][y].X >= 1)
            continue;
        if (t == 3 && i == 5)
            continue;

        if (isGreenOverlap(t, i, y))
            continue;

        green[i][y] = {t, idx};

        if (t == 2)
        {
            green[i][y + 1] = {t, idx};
        }

        if (t == 3)
        {
            green[i + 1][y] = {t, idx};
        }
        break;
    }

    return;
}

void blueMove(int t, int x, int y, int idx)
{
    for (int i = 5; i >= 0; i--)
    {

        bool isFind = 0;

        if (blue[x][i].X >= 1)
            continue;

        if (t == 2 && blue[x][i + 1].X >= 1)
            continue;
        if (t == 2 && i == 5)
            continue;
        if (t == 3 && blue[x + 1][i].X >= 1)
            continue;

        if (isBlueOverlap(t, i, x))
            continue;

        blue[x][i] = {t, idx};

        if (t == 2)
        {
            blue[x][i + 1] = {t, idx};
        }

        if (t == 3)
        {
            blue[x + 1][i] = {t, idx};
        }

        break;
    }

    return;
}

void blueSpill()
{
    int range = 0;
    for (int i = 0; i <= 1; i++)
    {

        for (int j = 0; j < 4; j++)
        {
            if (blue[j][i].X >= 1)
            {
                range++;
                break;
            }
        }
    }

    if (range == 0)
        return;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            tmp[i][j] = blue[i][j + 2 - range];
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 2; j < 6; j++)
        {
            blue[i][j] = tmp[i][j - 2];
        }
    }

    for (int i = 0; i <= 1; i++)
    {

        for (int j = 0; j < 4; j++)
        {
            blue[j][i] = {0, 0};
        }
    }
    return;
}

void greenSpill()
{
    int range = 0;
    for (int i = 0; i <= 1; i++)
    {

        for (int j = 0; j < 4; j++)
        {
            if (green[i][j].X >= 1)
            {
                range++;
                break;
            }
        }
    }

    if (range == 0)
        return;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            tmp[i][j] = green[i + 2 - range][j];
        }
    }

    for (int i = 2; i < 6; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            green[i][j] = tmp[i - 2][j];
        }
    }

    for (int i = 0; i <= 1; i++)
    {

        for (int j = 0; j < 4; j++)
        {
            green[i][j] = {0, 0};
        }
    }
    return;
}

void blockDiv()
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 4; j++)
        {

            if (green[i][j].X == 0)
                continue;
            bool isFind = 0;
            int idxNum = green[i][j].Y;
            for (int k = 0; k < 4; k++)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx < 0 || ny < 0 || nx >= 6 || ny >= 4)
                    continue;
                if (green[nx][ny].Y == idxNum)
                {
                    isFind = 1;
                    break;
                }
            }

            if (isFind == 0)
            {
                green[i][j] = {1, idxNum};
            }
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (blue[i][j].X == 0)
                continue;
            bool isFind = 0;
            int idxNum = blue[i][j].Y;
            for (int k = 0; k < 4; k++)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx < 0 || ny < 0 || nx >= 4 || ny >= 6)
                    continue;
                if (blue[nx][ny].Y == idxNum)
                {
                    isFind = 1;
                    break;
                }
            }

            if (isFind == 0)
            {
                blue[i][j] = {1, idxNum};
            }
        }
    }

    return;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int t, x, y;
        cin >> t >> x >> y;

        blueMove(t, x, y, i + 1);
        greenMove(t, x, y, i + 1);

        cout << i + 1 << "\n";

        greenPrint();
        ans += blueClear();
        ans += greenClear();

        blockDiv();

        blueSpill();
        greenSpill();

        blockDiv();

        bluePrint();
        greenPrint();
    }

    cout << ans << "\n";
    int blockAns = 0;
    for (int i = 2; i < 6; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (green[i][j].X > 0)
            {
                blockAns++;
            }
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 2; j < 6; j++)
        {
            if (blue[i][j].X > 0)
            {
                blockAns++;
            }
        }
    }

    cout << blockAns;
}

*/