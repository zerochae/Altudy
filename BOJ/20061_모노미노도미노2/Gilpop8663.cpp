#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g(6, vector<int>(4)), b(6, vector<int>(4)); // g,b : 6*4

int score = 0;

int now = 1;

int dx[4] = {0, 0, 0, 1};
int dy[4] = {0, 0, 1, 0};

int status(vector<int> &board) // 0 : empty , 1: full , 2: neither
{
    int cnt0 = 0;
    for (int i = 0; i < 4; i++)
    {
        if (board[i] == 0)
        {
            cnt0 += 1;
        }
    }

    if (cnt0 == 4)
    {
        return 0;
    }

    if (cnt0 == 0)
    {
        return 1;
    }

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

        if (row == 4 && t == 3)
            break;
        if (row == 5)
            break;

        row++;
    }
    board[row][v] = board[row + dx[t]][v + dy[t]] = now++;
    return;
}

void add(int t, int x, vector<vector<int>> &board)
{
    // 1. 블럭을 배치
    add_block(t, x, board, 0);

    // 2. 행이 꽉 찬 경우를 처리

    while (true)
    {
        int idx = 2; // 꽉 찬 행 찾기 0,1은 꽉 찬 행일 수 없음

        while (idx < 6 && status(board[idx]) != 1)
        {
            idx++;
        }
        if (idx == 6) //꽉 찬 행이 없을 경우
            break;

        score++;

        vector<vector<int>> tmp(6);

        for (int i = idx - 1; i >= 0; i--)
        {
            tmp[i] = board[i];
            board[i + 1] = tmp[i];
        }

        board[0] = vector<int>(4);
    }

    // 3. 0행 or 1행이 비지 않은 경우 처리

    if (status(board[0]) != 0) // 0행이 비지 않은 경우 ( 1행도 비지 않았음)
    {
        board.pop_back();
        board.pop_back();
        board.insert(board.begin(), 2, vector<int>(4));
    }
    else if (status(board[1]) != 0) // 0행은 비고 1행은 비지 않은 경우
    {
        board.pop_back();
        board.insert(board.begin(), vector<int>(4));
    }

    return;
}

void print(vector<vector<int>> &board)
{

    cout << "\n";
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    return;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

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
         << cnt << "\n";

    // cout << "파랑색"
    //      << "\n";
    // print(b);
    // cout << "초록색"
    //      << "\n";
    // print(g);
}
