#include <bits/stdc++.h>
using namespace std;

int n, m;

vector<int> arr[100005];

int ans[100005];

void func(int idx)
{
    for (int i = 0; i < arr[idx].size(); i++)
    {
        int next = arr[idx][i];
        // cout << next << "\n";
        ans[next] += ans[idx];
        func(next);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;
        if (num == -1)
            continue;

        arr[num].push_back(i);
    }

    for (int j = 0; j < m; j++)
    {
        int num, cost;
        cin >> num >> cost;
        ans[num] += cost;
    }

    func(1);

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
}
