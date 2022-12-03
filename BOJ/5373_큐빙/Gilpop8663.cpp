#include <bits/stdc++.h>
using namespace std;

/*
큐브가 돌아가면 4면의 색상이 움직이며 그 면의 옆에 해당하는 면은 방향에 따라 회전한다.

움직이는 행동 하나에 세로로 4면의 긴 색상이 이동하며

옆면의 색상들이 회전한다.

*/
int t, n, m;

char cube[7][3][3];

char color[] = {'w', 'y', 'r', 'o', 'g', 'b'};

const int UP = 0;
const int DOWN = 1;
const int FRONT = 2;
const int BACK = 3;
const int LEFT = 4;
const int RIGHT = 5;

void cubeSetting()
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {

                cube[i][j][k] = color[i];
            }
        }
    }
}

void cubePrint()
{
    cout << "\n";
    for (int i = 0; i < 6; i++)
    {
        if (i == 0)
            cout << "윗면"
                 << "\n";
        if (i == 1)
            cout << "앞면"
                 << "\n";
        if (i == 2)
            cout << "아랫면"
                 << "\n";
        if (i == 3)
            cout << "뒷면"
                 << "\n";
        if (i == 4)
            cout << "왼쪽면"
                 << "\n";
        if (i == 5)
            cout << "오른쪽면"
                 << "\n";
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                cout << cube[i][j][k] << " ";
            }
            cout << "\n";
        }
    }
    cout << "\n";
}

void rotate(int side, bool isclockwise)
{
    int rot = 1;
    if (!isclockwise)
        rot = 3;

    while (rot--)
    {
        char tmp[3][3];
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                tmp[j][2 - i] = cube[side][i][j];
            }
        }

        swap(cube[side], tmp);
    }

    return;
}

void rotateside(int side, bool isclockwise)
{
    rotate(side, isclockwise);
    int rot = 1;
    if (!isclockwise)
        rot = 3;

    int tmp;

    while (rot--)
    {
        if (side == FRONT)
        {
            for (int i = 0; i < 3; i++)
            {
                tmp = cube[UP][2][i];
                cube[UP][2][i] = cube[LEFT][2 - i][2];
                cube[LEFT][2 - i][2] = cube[DOWN][0][2 - i];
                cube[DOWN][0][2 - i] = cube[RIGHT][i][0];
                cube[RIGHT][i][0] = tmp;
            }
        }
        else if (side == BACK)
        {
            for (int i = 0; i < 3; i++)
            {
                tmp = cube[UP][0][i];
                cube[UP][0][i] = cube[RIGHT][i][2];
                cube[RIGHT][i][2] = cube[DOWN][2][2 - i];
                cube[DOWN][2][2 - i] = cube[LEFT][2 - i][0];
                cube[LEFT][2 - i][0] = tmp;
            }
        }
        else if (side == LEFT)
        {
            for (int i = 0; i < 3; i++)
            {
                tmp = cube[UP][i][0];
                cube[UP][i][0] = cube[BACK][i][0];
                cube[BACK][i][0] = cube[DOWN][i][0];
                cube[DOWN][i][0] = cube[FRONT][i][0];
                cube[FRONT][i][0] = tmp;
            }
        }
        else if (side == RIGHT)
        {
            for (int i = 0; i < 3; i++)
            {
                tmp = cube[UP][i][2];
                cube[UP][i][2] = cube[FRONT][i][2];
                cube[FRONT][i][2] = cube[DOWN][i][2];
                cube[DOWN][i][2] = cube[BACK][i][2];
                cube[BACK][i][2] = tmp;
            }
        }
        else if (side == UP)
        {
            for (int i = 0; i < 3; i++)
            {
                tmp = cube[FRONT][0][i];
                cube[FRONT][0][i] = cube[RIGHT][0][i];
                cube[RIGHT][0][i] = cube[BACK][2][2 - i];
                cube[BACK][2][2 - i] = cube[LEFT][0][i];
                cube[LEFT][0][i] = tmp;
            }
        }
        else if (side == DOWN)
        {
            for (int i = 0; i < 3; i++)
            {
                tmp = cube[FRONT][2][i];
                cube[FRONT][2][i] = cube[LEFT][2][i];
                cube[LEFT][2][i] = cube[BACK][0][2 - i];
                cube[BACK][0][2 - i] = cube[RIGHT][2][i];
                cube[RIGHT][2][i] = tmp;
            }
        }
    }
}

void cubeAnswerPrint()
{
    cout << "\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << cube[0][i][j] << " ";
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

    cin >> t;
    while (t--)
    {
        cin >> n;
        cubeSetting();

        for (int i = 0; i < n; i++)
        {
            string dir;
            cin >> dir;
            if (dir[0] == 'F')
                rotateside(FRONT, dir[1] == '+');
            else if (dir[0] == 'B')
                rotateside(BACK, dir[1] == '+');
            else if (dir[0] == 'L')
                rotateside(LEFT, dir[1] == '+');
            else if (dir[0] == 'R')
                rotateside(RIGHT, dir[1] == '+');
            else if (dir[0] == 'U')
                rotateside(UP, dir[1] == '+');
            else if (dir[0] == 'D')
                rotateside(DOWN, dir[1] == '+');
        }

        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
                cout << cube[UP][i][j];
            cout << '\n';
        }
    }
}
