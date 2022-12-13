#include <bits/stdc++.h>
using namespace std;

int n;

int arr[12][12];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int ans = 1e9;

int paper_cnt[5] = {5, 5, 5, 5, 5};

bool isEmpty()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 1)
                return false;
        }
    }
    return true;
}

bool isPossible(int x, int y, int size)
{
    for (int i = x; i <= x + size; i++)
    {
        for (int j = y; j <= y + size; j++)
        {
            if (i >= n || j >= n)
                return false;
            if (arr[i][j] == 0)
                return false;
        }
    }
    return true;
}

void setColorMove(int x, int y, int size, bool is_attatch)
{
    for (int i = x; i <= x + size; i++)
    {
        for (int j = y; j <= y + size; j++)
        {
            arr[i][j] = is_attatch;
        }
    }
}

void func(int attach_cnt)
{

    if (ans <= attach_cnt)
        return;
    if (isEmpty())
    {
        ans = min(ans, attach_cnt);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 1)
            {
                for (int k = 0; k <= 4; k++)
                {
                    if (paper_cnt[k] <= 0)
                        continue;
                    if (isPossible(i, j, k))
                    {
                        // 부착
                        paper_cnt[k]--;
                        setColorMove(i, j, k, 0);

                        // DFS
                        func(attach_cnt + 1);

                        // 제거
                        paper_cnt[k]++;
                        setColorMove(i, j, k, 1);
                    }
                }
                return;
            }
        }
    }

    return;
}

void print()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    n = 10;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    func(0);
    if (ans == 1e9)
    {
        ans = -1;
    }
    cout << ans;
}
