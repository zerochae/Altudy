#include <bits/stdc++.h>
using namespace std;

int n, k;

int arr[205];
bool ch[205] = {0};

int tmpNum[205];
int tmpCh[205] = {0};

int func()
{
    int cnt = 0;
    for (int i = 1; i <= 2 * n; i++)
    {
        if (arr[i] == 0)
        {
            cnt++;
        }
    }
    return cnt;
}

void reply()
{
    fill(tmpNum, tmpNum + 205, 0);
    fill(tmpCh, tmpCh + 205, 0);

    for (int i = 2; i <= 2 * n; i++)
    {
        tmpNum[i] = arr[i - 1];
        tmpCh[i] = ch[i - 1];
    }
    tmpNum[1] = arr[2 * n];
    tmpCh[1] = ch[2 * n];

    for (int i = 1; i <= 2 * n; i++)
    {
        arr[i] = tmpNum[i];
        ch[i] = tmpCh[i];
    }
    ch[n] = 0;

    return;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    int ans = 0;

    for (int i = 1; i <= 2 * n; i++)
    {
        cin >> arr[i];
    }

    while (func() < k)
    {
        ans++;
        reply();

        for (int i = n; i >= 1; i--)
        {
            if (arr[i + 1] > 0 && ch[i] == 1 && ch[i + 1] == 0)
            {
                ch[i + 1] = 1;
                ch[i] = 0;
                arr[i + 1]--;
            }
            ch[n] = 0;
        }

        if (arr[1] != 0)
        {
            ch[1] = 1;
            arr[1]--;
        }
    }

    cout << ans;
}
