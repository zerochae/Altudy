#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[55][55];

bool ch[55][55] = {0};

bool tmp[55][55] = {0};

bool prevCh[55][55] = {0};

int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

int mx[4] = {1, 1, -1, -1};
int my[4] = {1, -1, 1, -1};

void viewArr()
{
    cout << "\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    return;
}

int makeResult()
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            ans += arr[i][j];
        }
    }

    return ans;
}

void makeCloud()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (prevCh[i][j] == 1)
                continue;
            if (arr[i][j] >= 2)
            {
                ch[i][j] = 1;
                arr[i][j] -= 2;
            }
        }
    }
    return;
}

void waterCopy()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (prevCh[i][j] == 1)
            {
                int cnt = 0;
                for (int k = 0; k < 4; k++)
                {
                    int nx = i + mx[k];
                    int ny = j + my[k];

                    if (nx <= 0 || ny <= 0 || nx > n || ny > n)
                        continue;
                    if (arr[nx][ny] > 0)
                    {
                        cnt++;
                    }
                }

                arr[i][j] += cnt;
            }
        }
    }

    return;
}

void resetCloud()
{
    fill(&prevCh[0][0], &prevCh[54][55], 0);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            prevCh[i][j] = ch[i][j];
        }
    }

    fill(&ch[0][0], &ch[54][55], 0);
    return;
}

void plusOne()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (ch[i][j] == 1)
            {
                arr[i][j]++;
            }
        }
    }
    return;
}

void cloudMove(int dir)
{

    fill(&tmp[0][0], &tmp[54][55], 0);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (ch[i][j] == 1)
            {
                int nx = i + dx[dir];
                int ny = j + dy[dir];

                if (nx > n)
                {
                    nx = nx % n;
                }
                if (ny > n)
                {
                    ny = ny % n;
                }

                if (nx < 1)
                {
                    nx = n - nx;
                }

                if (ny < 1)
                {
                    ny = n - ny;
                }
                tmp[nx][ny] = 1;
                ch[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            ch[i][j] = tmp[i][j];
        }
    }
    return;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
        }
    }

    ch[n][1] = 1;
    ch[n][2] = 1;
    ch[n - 1][1] = 1;
    ch[n - 1][2] = 1;

    for (int i = 0; i < m; i++)
    {
        int dir, move;
        cin >> dir >> move;

        while (move--) // 1. 구름 이동
        {
            cloudMove(dir - 1);
        }

        plusOne(); // 2. 구름이 이동한 곳에 +1

        resetCloud(); // 3. 구름이 사라진다 . 구름이 사라진 자리는 따로 저장해둠

        waterCopy(); // 4. 물복사 버그 마법을 시전한다

        makeCloud(); // 5. 바구니에서 2 이상인 칸만 구름을 생성한다.
    }

    // viewArr();

    int ans = makeResult();

    cout << ans;
}
