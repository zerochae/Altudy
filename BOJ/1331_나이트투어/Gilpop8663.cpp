#include <bits/stdc++.h>
using namespace std;

string board[7][7];
bool ch[7][7];

char alp[6] = {'A', 'B', 'C', 'D', 'E', 'F'};

int dx[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
int dy[8] = {2, 2, 1, -1, -2, -2, -1, 1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // cout << "\n";

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            string strBoard;

            strBoard += alp[i];
            strBoard += to_string(j + 1);
            board[i][j] = strBoard;
            // cout << board[i][j] << " ";
        }
        // cout << "\n";
    }
    string first;
    cin >> first;

    int a, b;

    int sti, stj;
    for (int i = 0; i < 6; i++)

    {
        for (int j = 0; j < 6; j++)
        {
            if (board[i][j] == first)
            {
                a = i;
                b = j;
                sti = i;
                stj = j;
            }
        }
    }

    // cout << "str :" << first << " " << a << " " << b << "\n";

    for (int k = 0; k < 35; k++)
    {

        string str;
        cin >> str;
        bool flag = 0;

        for (int m = 0; m < 8; m++)
        {
            int nx = a + dx[m];
            int ny = b + dy[m];
            if (nx < 0 || ny < 0 || nx >= 6 || ny >= 6)
                continue;
            if (ch[nx][ny] == 1)
                continue;
            if (board[nx][ny] == str)
            {
                ch[nx][ny] = 1;
                a = nx;
                b = ny;
                flag = 1;
                break;
            }
        }

        // cout << "str :" << str << " " << a << " " << b << "\n";
        if (flag == 0)
        {
            cout << "Invalid";
            return 0;
        }
    }

    bool isFirst = 0;

    for (int i = 0; i < 8; i++)
    {
        int nx = a + dx[i];
        int ny = b + dy[i];
        if (nx < 0 || ny < 0 || nx >= 6 || ny >= 6)
            continue;
        if (ch[nx][ny] == 1)
            continue;
        if (nx == sti && ny == stj)
        {
            // cout << nx << " " << ny << "\n";
            isFirst = 1;
            break;
        }
    }

    if (isFirst)
    {
        cout << "Valid";
    }
    else
    {
        cout << "Invalid";
    }
}
