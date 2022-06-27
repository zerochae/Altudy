#include <bits/stdc++.h>
using namespace std;

int n, m;

queue<pair<long long, int>> q;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    q.push({n, 0});
    int ans = -1;

    while (!q.empty())
    {
        pair<long long, int> cur = q.front();

        q.pop();
        long long num = cur.first;
        // cout
        //     << num << "\n";
        if (num > m)
            continue;

        if (num == m)
        {
            ans = cur.second + 1;
            break;
        }

        if (num < m)
        {

            q.push({num * 2, cur.second + 1});
            q.push({num * 10 + 1, cur.second + 1});
        }
    }

    cout << ans;
}
