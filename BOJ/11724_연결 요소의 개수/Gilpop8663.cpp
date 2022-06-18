#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[1005][1005];
bool ch[1005];

queue<int> q;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int num1, num2;
        cin >> num1 >> num2;

        arr[num1][num2] = 1;
        arr[num2][num1] = 1;
    }

    int cnt = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (arr[i][j] == 1 && ch[j] == 0)
            {
                // ch[i] = 1;
                // ch[j] = 1;
                q.push(j);
                cnt++;
            }

            while (!q.empty())
            {

                int num = q.front();

                ch[num] = 1;

                q.pop();

                for (int k = 1; k <= n; k++)
                {
                    if (arr[num][k] == 1 && ch[k] == 0)
                    {
                        ch[k] = 1;
                        q.push(k);
                    }
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (ch[i] == 0)
        {
            cnt++;
        }
        // cout << ch[i] << " ";
    }
    cout << cnt;
}