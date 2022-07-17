#include <bits/stdc++.h>
using namespace std;

int n, m;

bool arr[105][105];
bool ch[105] = {0};

int ansIdx = 0;
int ans = 1e9;

queue<pair<int, int>> q;

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

    for (int i = 1; i <= n; i++)
    {
        fill(ch, ch + 105, 0);
        q.push({i, 0});
        ch[i] = 1;

        int sum = 0;

        while (!q.empty())
        {
            pair<int, int> cur = q.front();
            q.pop();

            int num = cur.first;
            int cnt = cur.second;
            // cout << cnt << " " << num << "\n";
            for (int j = 1; j <= n; j++)
            {
                if (ch[j] == 1)
                    continue;
                if (arr[num][j] == 1)
                {
                    sum += cnt + 1;
                    ch[j] = 1;
                    q.push({j, cnt + 1});
                }
            }
        }
        if (ans > sum)
        {
            ans = sum;
            ansIdx = i;
        }

        // cout << sum << "\n";
    }

    cout << ansIdx;
}