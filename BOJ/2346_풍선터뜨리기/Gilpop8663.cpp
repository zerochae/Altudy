#include <bits/stdc++.h>
using namespace std;

int n;

int arr[1005];
bool ch[1005];

int check(int idx, bool dir)
{ // true 는 오른쪽(양수) , false 는 왼쪽 (음수)

    if (dir == 1)
    {

        for (int i = idx; i <= n; i++)
        {
            if (ch[i] == 1)
            {
                continue;
            }
            else
            {
                return i;
            }
        }

        for (int i = 1; i < idx; i++)
        {
            if (ch[i] == 1)
            {
                continue;
            }
            else
            {
                return i;
            }
        }
    }
    else
    {
        for (int i = idx; i >= 1; i--)
        {
            if (ch[i] == 1)
            {
                continue;
            }
            else
            {
                return i;
            }
        }

        for (int i = n; i > idx; i--)
        {
            if (ch[i] == 1)
            {
                continue;
            }
            else
            {
                return i;
            }
        }
    }
    return 0;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    cout << 1 << " ";

    int cur = 1;
    int score = arr[1];
    int cnt = 1;

    int idxCnt = 0;
    ch[1] = 1;

    while (true)
    {

        if (cnt == n)
            break;
        int tmp = abs(score);
        idxCnt = 0;
        while (true)
        {
            // cout << tmp << " " << idxCnt << " 이거 인덱스CNt임 "
            //      << " " << cur
            //      << "\n";
            if (tmp - 1 == idxCnt)
            {
                break;
            }
            if (ch[cur] == 0)
            {
                idxCnt++;
            }
            if (score < 0)
            {

                if (cur > 1)
                    cur--;
                else
                    cur = n;
            }
            else if (score > 0)
            {
                if (cur < n)
                    cur++;
                else
                    cur = 1;
            }
        }

        // cout << cur << " "
        //      << "\n";
        if (ch[cur] == 1)
        {
            if (score > 0)
                cur = check(cur, 1);
            if (score < 0)
                cur = check(cur, 0);
        }

        score = arr[cur];
        ch[cur] = 1;
        cnt++;

        cout << cur << " ";
    }
}

/*

5

-5 -5 -5 -5 -5

*/