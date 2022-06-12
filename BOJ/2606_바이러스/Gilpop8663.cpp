#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[105][105];

int ch[105];

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

    queue<int> q;
    ch[1] = 1;
    q.push(1);
    int cnt = 0;
    // for (int i = 1; i <= n; i++)
    // {
    //     // cout << arr[1][i] << " ";
    //     if (arr[1][i] == 1)
    //     {
    //         q.push(i);
    //         ch[i] = 1;
    //         cnt++;
    //     }
    // }
    while (!q.empty())
    {
        int num = q.front();
        q.pop();

        // cout << num << "\n";
        for (int i = 1; i <= n; i++)
        {
            if (arr[num][i] == 1 && ch[i] == 0)
            {
                q.push(i);
                ch[i] = 1;
                cnt++;
            }
        }
    }
    cout << cnt;
}
