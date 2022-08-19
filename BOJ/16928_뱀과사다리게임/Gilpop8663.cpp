#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[105];
bool ch[105];

queue<pair<int, int>> q;

vector<int> s;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        int num, num2;
        cin >> num >> num2;
        arr[num] = num2;
    }

    for (int i = 0; i < m; i++)
    {
        int num, num2;
        cin >> num >> num2;
        arr[num] = num2;
    }

    ch[1] = 0;
    q.push({1, 0});

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        int x = cur.first;
        int cnt = cur.second;

        if (x == 100)
        {
            cout << cnt;
            return 0;
        }

        for (int i = 1; i <= 6; i++)
        {
            int nx = x + i;
            if (nx < 0 || nx >= 101)
                continue;
            if (ch[nx] == 1)
                continue;
            if (arr[nx] != 0)
            {
                q.push({arr[nx], cnt + 1});
                ch[arr[nx]] = 1;
                ch[nx] = 1;
            }
            else
            {
                q.push({nx, cnt + 1});
                ch[nx] = 1;
            }
        }
    }

    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i] << " ";
    }
}
