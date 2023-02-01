#include <bits/stdc++.h>
using namespace std;

int n, m;

vector<int> arr[205];

int plan[1005];

bool ch[205];

vector<int> p(205, -1);

int find(int x)
{
    if (p[x] < 0)
    {
        return x;
    }
    return p[x] = find(p[x]);
}

void unionFunc(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v)
        return;
    if (p[u] > p[v])
    {
        swap(u, v);
    }
    p[u] += p[v];
    p[v] = u;
    return;
}

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
                unionFunc(i, j);
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        cin >> plan[i];
    }

    int rootNum = find(plan[0]);
    for (int i = 0; i < m; i++)
    {
        if (rootNum != find(plan[i]))
        {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
}
