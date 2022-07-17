#include <bits/stdc++.h>
using namespace std;

int n, m;

vector<int> arr[10005];

// bool arr[10005][10005];

bool ch[10005] = {0};

queue<int> q;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int num, num2;
        cin >> num >> num2;

        arr[num2].push_back(num);
        // arr[num2][num] = 1;
    }

    int ans = 0;

    vector<int> v(n);

    int vIdx = 0;
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;

        fill(ch + 1, ch + n + 1, 0);

        q.push(i);
        ch[i] = 1;

        while (!q.empty())
        {
            int num = q.front();

            q.pop();

            for (int k = 0; k < arr[num].size(); k++)
            {
                int nv = arr[num][k];
                if (ch[nv] == 1)
                    continue;
                ch[nv] = 1;
                q.push(nv);
                sum++;
            }
        }

        // cout << sum << "\n";

        if (sum > ans)
        {
            ans = sum;
            vIdx = 0;
            v[vIdx++] = i;
        }
        else if (sum == ans)
        {
            v[vIdx++] = i;
        }
    }

    for (int i = 0; i < vIdx; i++)
    {
        cout << v[i] << " ";
    }
}
