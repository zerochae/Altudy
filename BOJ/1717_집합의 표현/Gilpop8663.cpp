#include <bits/stdc++.h>
using namespace std;

int n, m;

vector<int> arr[1000005];

vector<int> p(1000005, -1);

int find(int x)
{
    if (p[x] < 0)
        return x;
    return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v)
{
    u = find(u);
    v = find(v);

    if (u == v)
        return 0;

    if (p[u] > p[v])
    {
        swap(u, v);
    }

    p[u] += p[v];
    p[v] = u;
    return 1;
}

bool is_check_group(int u, int v)
{
    u = find(u);
    v = find(v);

    if (u == v)
        return 0;
    return 1;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        arr[i].push_back(i);
    }

    for (int i = 0; i < m; i++)
    {
        int isSum, a, b;
        cin >> isSum >> a >> b;

        if (isSum == 0)
        {
            is_diff_group(a, b);
        }

        if (isSum == 1)
        {
            bool isCheck = is_check_group(a, b);

            if (isCheck == 0)
            {
                cout << "YES"
                     << "\n";
            }
            else
            {
                cout << "NO"
                     << "\n";
            }
        }
    }
}
