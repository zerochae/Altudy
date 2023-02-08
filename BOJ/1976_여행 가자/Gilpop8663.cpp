#include <bits/stdc++.h>
using namespace std;

int n, m;

vector<int> arr[205];

int plan[1005];

bool ch[205];

queue<int> q;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int num;
            cin >> num;

            if (num == 1)
            {
                arr[i].push_back(j);
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        cin >> plan[i];
    }

    ch[plan[0]] = 1;
    q.push(plan[0]);

    while (!q.empty())
    {
        int num = q.front();
        q.pop();

        for (int i = 0; i < arr[num].size(); i++)
        {
            int nxtNum = arr[num][i];

            if (ch[nxtNum] == 1)
                continue;
            ch[nxtNum] = 1;
            q.push(nxtNum);
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (ch[plan[i]] == 0)
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}
