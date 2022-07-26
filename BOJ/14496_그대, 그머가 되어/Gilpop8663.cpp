#include <bits/stdc++.h>

using namespace std;

int a, b;

int n, m;

bool arr[1005][1005];

bool ch[1005];

queue<pair<int, int>> q;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int num, num2;

        cin >> num >> num2;

        arr[num][num2] = 1;
        arr[num2][num] = 1;
    }

    ch[a] = 1;
    q.push({a, 0});

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        int x = cur.first;

        int dis = cur.second;

        if (x == b)
        {
            cout << dis;
            return 0;
        }

        for (int i = 1; i <= n; i++)
        {
            if (ch[i] == 1)
                continue;
            if (arr[x][i] == 1)
            {
                ch[i] = 1;
                q.push({i, dis + 1});
            }
        }
    }

    cout << -1;
}