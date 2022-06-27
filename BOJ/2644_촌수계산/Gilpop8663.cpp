#include <bits/stdc++.h>
using namespace std;

string str;
int n, m;

int x, y;

int arr[105][105];
int ch[105];
int d[105];

queue<int> q;

// int ans = 0;

// int func(int a, int sum)
// {
//     ch[a] = 1;

//     // cout << a << " " << y << "\n";

//     if (a == y)
//     {
//         ans = sum;
//         return 0;
//     }

//     for (int i = 1; i <= n; i++)
//     {
//         if (ch[i] == 1)
//             continue;
//         if (arr[a][i] == 1)
//         {
//             func(i, sum + 1);
//         }
//     }
//     return 0;
// }

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    cin >> x >> y;

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int num1, num2;

        cin >> num1 >> num2;

        arr[num1][num2] = 1;
        arr[num2][num1] = 1;
    }

    q.push(x);
    ch[x] = 1;

    int ans = 0;
    int cnt = 0;
    d[x] = 0;

    // func(x, 0);

    while (!q.empty())
    {
        int num = q.front();
        q.pop();

        // cout << num << " " << d[num] << "\n";

        cnt++;
        for (int i = 1; i <= n; i++)
        {
            if (ch[i] == 1)
                continue;
            if (arr[num][i] == 1)
            {
                ch[num] = 1;
                q.push(i);
                d[i] = d[num] + 1;
            }
        }
    }

    ans = d[y];

    if (ans == 0)
    {
        cout << -1;
    }
    else
    {
        cout << d[y];
    }
}
