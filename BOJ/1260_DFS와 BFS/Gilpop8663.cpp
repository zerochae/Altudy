#include <bits/stdc++.h>
using namespace std;

int n, m, s;

int arr[1005][1005];
bool ch[1005] = {0};

queue<int> q;
stack<int> t;

void DFS(int a)
{
    ch[a] = 1;

    cout << a << " ";
    for (int i = 1; i <= n; i++)
    {
        if (ch[i] == 1)
            continue;
        if (arr[a][i] == 1)
        {
            ch[i] = 1;
            DFS(i);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> s;

    for (int i = 0; i < m; i++)
    {

        int num1, num2;

        cin >> num1 >> num2;

        arr[num1][num2] = 1;
        arr[num2][num1] = 1;
    }

    // DFS

    ch[s] = 1;

    DFS(s);

    cout << "\n";

    // BFS

    fill(ch, ch + 1005, 0);

    ch[s] = 1;
    q.push(s);

    while (!q.empty())
    {

        int num = q.front();

        q.pop();
        cout << num << " ";
        for (int j = 1; j <= n; j++)
        {
            if (ch[j] == 1)
                continue;
            if (arr[num][j] == 1)
            {
                ch[j] = 1;
                q.push(j);
            }
        }
    }

    cout << "\n";
}
