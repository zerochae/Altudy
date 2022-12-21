#include <bits/stdc++.h>
using namespace std;

int n, m, k;

int arr[55][55];
int copy_arr[55][55];
int tmp[55][55];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

vector<int> state;

tuple<int, int, int> cal[7];

void tornado(int x, int y, int s)
{

    int nx = x;
    int ny = y;
    int dir = 0;
    int nCount = 0;
    int tmpNumber = tmp[x][y];
    while (1)
    {
        if (dir == 4 && nx == x && ny == y)
            break;
        int number = tmpNumber;
        nx += dx[dir];
        ny += dy[dir];
        tmpNumber = tmp[nx][ny];
        tmp[nx][ny] = number;
        nCount++;

        if (nCount == s - 1)
        {
            dir++;
            nCount = 0;
        }
    }

    return;
}

void printTmp(int s)
{
    cout << "\n";
    for (int i = 1; i <= 2 * s + 1; i++)
    {
        for (int j = 1; j <= 2 * s + 1; j++)
        {
            cout << tmp[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void rotate(int x, int y, int s)
{

    for (int i = 1; i <= 2 * s + 1; i++)
    {
        for (int j = 1; j <= 2 * s + 1; j++)
        {
            tmp[i][j] = copy_arr[x - s - 1 + i][y - s - 1 + j];
        }
    }

    for (int i = 1; i <= s; i++)
    {
        int count = 2 * s + 1;
        tornado(i, i, 2 * s + 1 - ((i - 1) * 2));
    }

    for (int i = 1; i <= 2 * s + 1; i++)
    {
        for (int j = 1; j <= 2 * s + 1; j++)
        {
            copy_arr[x - s - 1 + i][y - s - 1 + j] = tmp[i][j];
        }
    }
}

void print()
{
    cout << "\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << copy_arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int calAnswer()
{
    int minNum = 1e9;
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = 1; j <= m; j++)
        {
            sum += copy_arr[i][j];
        }
        if (minNum > sum)
        {
            minNum = sum;
        }
    }

    return minNum;
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
            copy_arr[i][j] = arr[i][j];
        }
    }

    for (int i = 0; i < k; i++)
    {
        int x, y, s;
        cin >> x >> y >> s;
        cal[i] = {x, y, s};
        rotate(x, y, s);
    }

    for (int i = 0; i < k; i++)
    {
        state.push_back(i);
    }

    int ans = 1e9;

    do
    {
        // 복사
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                copy_arr[i][j] = arr[i][j];
            }
        }

        // 회전
        for (int i = 0; i < k; i++)
        {
            int num = state[i];
            int x = get<0>(cal[num]);
            int y = get<1>(cal[num]);
            int s = get<2>(cal[num]);
            rotate(x, y, s);
        }

        // 정답 도출

        int sumNum = calAnswer();
        if (ans > sumNum)
        {
            ans = sumNum;
        }
    } while (next_permutation(state.begin(), state.end()));

    cout << ans;
}

/*
5 6 3
1 2 3 2 5 6
3 8 7 2 1 3
8 2 3 1 4 5
3 4 5 1 1 1
9 3 2 1 4 3
3 4 2
3 4 2
4 2 1

*/