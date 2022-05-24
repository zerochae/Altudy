#include <bits/stdc++.h>
using namespace std;

int n;

int arr[30][30];

bool ch[30][30];

int check()
{

    int ans = 0;

    for (int i = 0; i < 5; i++) //가로,세로
    {
        int cnt = 0;
        int hor = 0;
        for (int j = 0; j < 5; j++)
        {
            if (ch[i][j] == 1)
            {
                cnt++;
            }

            if (ch[j][i] == 1)
            {
                hor++;
            }
        }
        if (cnt == 5)
            ans++;
        if (hor == 5)
            ans++;
    }

    //왼쪽 대각선

    int leftCnt = 0;
    int rightCnt = 0;
    for (int i = 0; i < 5; i++)
    {
        if (ch[i][i] == 1)
        {
            leftCnt++;
        }

        if (ch[i][4 - i] == 1)
        {
            rightCnt++;
        }
    }

    if (leftCnt == 5)
    {
        ans++;
    }

    if (rightCnt == 5)
    {
        ans++;
    }

    return ans;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> arr[i][j];
        }
    }
    int ansFlag = false;
    for (int i = 0; i < 5; i++)
    {
        if (ansFlag == true)
        {
            break;
        }
        for (int j = 0; j < 5; j++)
        {
            int num;
            cin >> num;
            bool flag = false;

            for (int k = 0; k < 5; k++) // 체크
            {
                if (flag == true)
                {
                    break;
                }
                for (int l = 0; l < 5; l++)
                {
                    if (arr[k][l] == num)
                    {
                        ch[k][l] = 1;
                        flag = 1;
                        break;
                    }
                }
            }

            //  check();

            // cout << check() << "\n";
            if (check() >= 3)
            {
                cout << (i)*5 + j + 1;
                // cout << check() << " " << i << " " << j << " " << num << "\n";
                ansFlag = true;
                break;
            }
            // cout << check() << " " << i << " " << j << " " << num << "\n";
        }
    }
}
