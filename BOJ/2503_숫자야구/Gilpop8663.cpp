#include <bits/stdc++.h>
using namespace std;

int n, m;

map<string, string> s;

bool arr[1005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 123; i < 1000; i++)
    {
        arr[i] = 1;
        string str = to_string(i);

        if (str[0] == str[1] || str[1] == str[2] || str[0] == str[2])
            arr[i] = 0;
        if (str[0] - '0' == 0 || str[1] - '0' == 0 || str[2] - '0' == 0)
            arr[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        string num;
        int strike, ball;

        cin >> num >> strike >> ball;

        for (int j = 123; j <= 999; j++)
        {
            int ansS = 0;
            int ansB = 0;

            if (arr[j] == 0)
                continue;

            string ans = to_string(j);

            for (int k = 0; k < 3; k++)
            {
                for (int m = 0; m < 3; m++)
                {
                    if (k == m && ans[k] == num[m])
                    {
                        ansS++;
                    }
                    else if (k != m && ans[k] == num[m])
                    {
                        ansB++;
                    }
                }
            }
            if (ansS != strike || ansB != ball)
                arr[j] = 0;
        }
    }
    int ansNumber = 0;
    for (int i = 123; i < 1000; i++)
    {
        if (arr[i] == 1)
        {
            ansNumber++;
        }
    }

    cout << ansNumber;
}