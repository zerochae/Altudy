#include <bits/stdc++.h>

using namespace std;

int t;

int n, curX, curY, scoreX, scoreY;

bool arr[105][105];
bool ans[105][105] = {0};

bool ch[105] = {0};

queue<int> q;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    // cout << "\n";
    for (int i = 0; i < n; i++)
    {
        fill(ch, ch + 105, 0);

        q.push(i);

        while (!q.empty())
        {
            int num = q.front();
            q.pop();

            for (int k = 0; k < n; k++)
            {
                if (ch[k] == 1)
                    continue;
                if (arr[num][k] == 1)
                {

                    ch[k] = 1;
                    ans[i][k] = 1;
                    q.push(k);
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}
