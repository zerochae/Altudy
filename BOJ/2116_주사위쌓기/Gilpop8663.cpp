#include <bits/stdc++.h>
using namespace std;

int n;
// 2000000000
int d[35];

int arr[10005][7];

bool number[7] = {0};

int ans = 0;

void func(int cnt, int k, int sum)
{

    if (cnt == n)
    {
        ans = max(ans, sum);
        return;
    }
    fill(number, number + 7, 0);

    number[k] = 1;

    int idx = -1;
    int maxNum = 0;

    for (int i = 0; i < 6; i++)
    {

        if (arr[cnt][i] == k)
        {
            idx = i;
        }
    }

    if (idx == 0)
    {
        idx = 5;
    }
    else if (idx == 1)
    {
        idx = 3;
    }
    else if (idx == 2)
    {
        idx = 4;
    }
    else if (idx == 3)
    {
        idx = 1;
    }
    else if (idx == 4)
    {
        idx = 2;
    }
    else if (idx == 5)
    {
        idx = 0;
    }

    number[arr[cnt][idx]] = 1;

    for (int i = 1; i <= 6; i++)
    {
        if (number[i] == 1)
            continue;

        maxNum = max(i, maxNum);
    }

    func(cnt + 1, arr[cnt][idx], sum + maxNum);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= 6; i++)
    {
        func(0, i, 0);
    }

    cout << ans;
}
