#include <bits/stdc++.h>
using namespace std;

int n, m, k, x;

vector<int> arr[300005];
bool ch[300005];

queue<pair<int, int>> q;

vector<int> ans;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k >> x;

    for (int i = 0; i < m; i++)
    {
        int num1, num2;
        cin >> num1 >> num2;
        arr[num1].push_back(num2);
    }

    q.push({x, 0});

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        int num = cur.first;
        int cnt = cur.second;

        q.pop();

        if (ch[num] == 1)
            continue;

        if (cnt == k)
        {
            ans.push_back(num);
        }

        ch[num] = 1;

        int n = arr[num].size();

        for (int i = 0; i < n; i++)
        {
            int number = arr[num][i];
            if (ch[number] == 1)
                continue;
            q.push({number, cnt + 1});
        }
    }

    sort(ans.begin(), ans.end());

    if (ans.size() > 0)
    {

        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << "\n";
        }
    }
    else
    {
        cout << -1;
    }
}
