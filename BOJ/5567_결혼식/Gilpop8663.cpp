#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[505][505];

bool ch[505];

queue<pair<int, int>> q;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ans = 0;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int num1, num2;
        cin >> num1 >> num2;

        arr[num1][num2] = 1;
        arr[num2][num1] = 1;
    }

    q.push({1, 0});

    while (!q.empty())
    {
        pair<int, int> cur = q.front();

        int num = cur.first;
        int cnt = cur.second;
        q.pop();

        if (ch[num] == 1)
            continue;

        if (cnt <= 2 && cnt != 0)
        {
            ans++;
        }

        ch[num] = 1;

        for (int i = 1; i <= n; i++)
        {
            if (ch[i] == 1)
                continue;
            if (arr[num][i] == 1)
            {
                q.push({i, cnt + 1});
            }
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << ch[i] << " ";
    // }
    // cout << "\n";

    cout << ans;
}
