#include <bits/stdc++.h>
using namespace std;

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill)
{
    int answer = 0;

    int n = board.size();
    int m = board[0].size();

    int arr[n + 2][m + 2];

    fill(&arr[0][0], &arr[n - 1][m], 0);

    for (int i = 0; i < skill.size(); i++)
    {
        int type = skill[i][0];
        int r1, r2, c1, c2, deg;

        r1 = skill[i][1];
        c1 = skill[i][2];
        r2 = skill[i][3];
        c2 = skill[i][4];

        deg = skill[i][5];

        if (type == 1)
        {
            arr[r1][c1] -= deg;
            arr[r2 + 1][c2 + 1] -= deg;
            arr[r2 + 1][c1] -= -deg;
            arr[r1][c2 + 1] -= -deg;
        }
        else
        {
            arr[r1][c1] += deg;
            arr[r2 + 1][c2 + 1] += deg;
            arr[r2 + 1][c1] += -deg;
            arr[r1][c2 + 1] += -deg;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i + 1][j] += arr[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][j + 1] += arr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            board[i][j] += arr[i][j];
            if (board[i][j] > 0)
            {
                answer++;
            }
        }
    }
    return answer;
}