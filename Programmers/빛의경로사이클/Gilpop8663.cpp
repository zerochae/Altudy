#include <bits/stdc++.h>

using namespace std;

int n, m;

bool ch[505][505][5] = {0};

vector<string> arr;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

// 직진 : k ,  왼쪽: (k+3)%4 , 오른쪽 : (k+1)%4;

/*
위 : k=3임  직진 : 3 , 왼쪽:2 , 오른쪽 : 0
공식을 사용 : 직진 : 3 , 왼쪽 : 2, 오른쪽 : 0

아래 : k=1임 직진 : 1 , 왼쪽 : 0 , 오른쪽 : 2
공식 :       직진 : 1 , 왼쪽 : 0 , 오른쪽 : 2

왼쪽 : k=2임 직진 : 2 , 왼쪽 : 1 , 오른쪽 :3
공식 :       직진 : 2 , 왼쪽 : 1 , 오른쪽 :3

오른쪽 : k=0임 직진: 0 왼쪽 : 3 , 오른쪽 : 1
공식 :         직진 :0 왼쪽 :3    오른쪽 : 1

*/
int change_dir(char c, int dir)
{
    if (c == 'L')
    {
        return (dir + 3) % 4;
    }

    return (dir + 1) % 4;
}

int func(int x, int y, int dir, int cnt)
{
    if (ch[x][y][dir] == true)
        return cnt;

    ch[x][y][dir] = 1;

    int nx = x;
    int ny = y;
    int nd = dir;

    if (arr[x][y] != 'S')
    {
        nd = change_dir(arr[x][y], dir);
    }
    nx = x + dx[nd];
    ny = y + dy[nd];

    if (nx < 0)
        nx = n - 1;
    if (nx >= n)
        nx = 0;
    if (ny < 0)
        ny = m - 1;
    if (ny >= m)
        ny = 0;

    return func(nx, ny, nd, cnt + 1);
}

vector<int> solution(vector<string> grid)
{
    vector<int> answer;

    arr = grid;

    n = grid.size();
    m = grid[0].length();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                int result = func(i, j, k, 0);
                if (result != 0)
                    answer.push_back(result);
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}