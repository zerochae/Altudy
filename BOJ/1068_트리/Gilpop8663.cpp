#include <bits/stdc++.h>
using namespace std;

int n, k;

vector<int> arr[55];
bool ch[55] = {0};

queue<int> q;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int root = 0;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        if (num == -1)
        {
            root = i;
            continue;
        }
        arr[num].push_back(i);
    }

    cin >> k;

    ch[k] = 1;

    if (ch[root] == 0)
    {

        ch[root] = 1;
        q.push(root);
    }

    int ans = 0;

    while (!q.empty())
    {
        int num = q.front();
        q.pop();

        int cnt = 0;

        int m = arr[num].size();

        for (int i = 0; i < m; i++)
        {
            int number = arr[num][i];
            if (ch[number] == 1)
                continue;
            cnt++;
            ch[number] = 1;
            q.push(number);
        }

        if (cnt == 0)
        {
            ans++;
        }
        }
    cout << ans;
}
