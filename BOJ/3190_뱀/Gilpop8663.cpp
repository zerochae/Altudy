#include <bits/stdc++.h>
using namespace std;

int n, k, l;

int arr[255][255];
bool ch[255][255] = {0};

vector<pair<int, int>> apple;
vector<pair<int, char>> info;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

//  아래 : 1 ,0 >>  L :0,1  R : 0,-1
//          0   >>      1     >>  3

// 위 :  -1,0  >> L : 0,-1  R : 0,1
//         2    >>     3     >>   1

//왼쪽 : 0,-1  >> L : 1,0   R : -1,0
//        3    >>     0  >>    2

//오른쪽  0,1  >>  L: -1,0  R : 1,0
//        1    >>    2  >> 0

queue<pair<int, int>> q;

int curDir = 1;

int ans = 0;

int changeDir(int dir, char str)
{
    if (dir == 0)
    {
        if (str == 'L')
        {
            return 1;
        }
        else
        {
            return 3;
        }
    }
    else if (dir == 1)
    {
        if (str == 'L')
        {
            return 2;
        }
        else
        {
            return 0;
        }
    }
    else if (dir == 2)
    {
        if (str == 'L')
        {
            return 3;
        }
        else
        {
            return 1;
        }
    }
    else if (dir == 3)
    {
        if (str == 'L')
        {
            return 0;
        }
        else
        {
            return 2;
        }
    }
    return 9;
}

pair<int, int> advance(int curX, int curY, int dir, int cnt)
{
    int nx = curX;
    int ny = curY;

    while (cnt--)
    {
        nx += dx[dir];
        ny += dy[dir];

        // cout << nx << " " << ny << " " << dir << "\n";

        if (nx <= 0 || ny <= 0 || nx > n || ny > n || ch[nx][ny] == 1)
            return {-9999, -9999};

        ans++;
        if (arr[nx][ny] == 2)
        {
            ch[nx][ny] = 1;
            q.push({nx, ny});
            arr[nx][ny] = 0;
        }
        else
        {
            ch[nx][ny] = 1;
            q.push({nx, ny});
            auto chCur = q.front();
            q.pop();
            int chX = chCur.first;
            int chY = chCur.second;

            // cout << chX << " " << chY << "\n";

            ch[chX][chY] = 0;
        }
    }

    return {nx, ny};
}

int func()
{
    int nx, ny;
    int prevCnt = 0;
    for (int i = 0; i < l; i++)
    {
        int cnt = info[i].first;
        char dir = info[i].second;

        // cout << cnt << " " << dir << "\n";
        if (i == 0)
        {
            auto cur = advance(1, 1, curDir, cnt - prevCnt);
            nx = cur.first;
            ny = cur.second;
            prevCnt = cnt;
        }
        else
        {
            auto cur = advance(nx, ny, curDir, cnt - prevCnt);
            nx = cur.first;
            ny = cur.second;
            prevCnt = cnt;
        }

        if (nx == -9999 && ny == -9999)
        {
            return ans;
        }
        else
        {
            curDir = changeDir(curDir, dir);
        }
    }

    advance(nx, ny, curDir, 105);

    return ans;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 0; i < k; i++)
    {
        int num, num2;
        cin >> num >> num2;

        arr[num][num2] = 2;
    }

    cin >> l;

    for (int i = 0; i < l; i++)
    {
        int num;
        char str;
        cin >> num >> str;
        info.push_back({num, str});
    }

    ch[1][1] = 1;
    q.push({1, 1});

    int realAns = func();

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    cout << realAns + 1;
}
