#include <bits/stdc++.h>
using namespace std;

int F, S, G, U, D;

queue<pair<int, int>> q;

bool ch[1000005] = {0};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> F >> S >> G >> U >> D;

    ch[S] = 1;
    q.push({S, 0});

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        int x = cur.first;
        int cnt = cur.second;

        // cout << x << " " << cnt << "\n";
        if (x == G)
        {
            cout << cnt;
            return 0;
        }

        int arr[2] = {U, D * -1};
        for (int i = 0; i < 2; i++)
        {

            int nx = x + arr[i];

            if (nx < 1 || nx > F || ch[nx] == 1)
                continue;
            ch[nx] = 1;
            q.push({nx, cnt + 1});
        }
    }
    cout << "use the stairs";
}
