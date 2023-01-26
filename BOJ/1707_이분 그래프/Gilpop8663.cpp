#include <bits/stdc++.h>
using namespace std;

int t, n, m;

int ch[20005];
vector<int> arr[20005];

queue<int> q;

bool is_not_diff()
{
    for (int i = 1; i <= n; i++)
    {
        int arrSize = arr[i].size();

        for (int j = 0; j < arrSize; j++)
        {
            int number = arr[i][j];

            if (ch[i] == ch[number])
            {
                return 0;
            }
        }
    }
    return 1;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while (t--)
    {

        cin >> n >> m;
        fill(ch, ch + n + 1, 0);

        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            arr[u].push_back(v);
            arr[v].push_back(u);
        }

        for (int i = 1; i <= n; i++)
        {
            if (ch[i] == 0)
            {
                ch[i] = 1;
                q.push(i);

                while (!q.empty())
                {
                    auto cur = q.front();
                    q.pop();

                    int color = 0;
                    if (ch[cur] == 2)
                    {
                        color = 1;
                    }
                    else if (ch[cur] == 1)
                    {
                        color = 2;
                    }

                    for (auto nxt : arr[cur])
                    {
                        if (ch[nxt] == 0)
                        {
                            ch[nxt] = color;
                            q.push(nxt);
                        }
                    }
                }
            }
        }

        if (is_not_diff())
        {
            cout << "YES"
                 << "\n";
        }
        else
        {
            cout << "NO"
                 << "\n";
        }

        for (int i = 0; i <= n; i++)
        {
            arr[i].clear();
        }
    }
}