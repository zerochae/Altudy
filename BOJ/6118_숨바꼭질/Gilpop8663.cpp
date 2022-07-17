#include <bits/stdc++.h>
using namespace std;

int n, m;

int d[20005];

bool ch[20005] = {0};

vector<int> arr[20005];

queue<pair<int, int>> q;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int num, num2;
        cin >> num >> num2;

        arr[num].push_back(num2);
        arr[num2].push_back(num);
    }

    fill(d, d + n + 1, 99999);

    ch[1] = 1;
    q.push({1, 0});

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        int x = cur.first;
        int dis = cur.second;

        d[x] = min(d[x], dis);

        for (int i = 0; i < arr[x].size(); i++)
        {
            int to = arr[x][i];

            if (ch[to] == 1)
                continue;
            ch[to] = 1;
            q.push({to, dis + 1});
        }
    }

    int cnt = 1, ans = 0, idx = 0;
    for (int i = 1; i <= n; i++)
    {
        // cout << d[i] << " ";
        if (ans < d[i])
        {
            cnt = 1;
            ans = d[i];
            idx = i;
        }
        else if (ans == d[i])
        {
            cnt++;
        }
    }

    cout << idx << " " << ans << " " << cnt;
}
