#include <bits/stdc++.h>
using namespace std;

int A, B, N, M;

bool ch[100005];

int d[100005];

queue<pair<int, int>> q;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> B >> N >> M;

    fill(d, d + 100001, 999999);

    q.push({0, N});
    ch[N] = 0;

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        int cnt = cur.first;
        int dis = cur.second;

        if (dis == M)
        {
            cout << cnt;
            return 0;
        }

        int check[8] = {dis - 1, dis + 1, dis + A, dis + B, dis - A, dis - B, dis * A, dis * B};

        for (int i = 0; i < 8; i++)
        {
            if (check[i] >= 0 && check[i] <= 100000)
            {
                if (!ch[check[i]])
                {
                    ch[check[i]] = 1;
                    q.push({cnt + 1, check[i]});
                }
            }
        }
    }
}
