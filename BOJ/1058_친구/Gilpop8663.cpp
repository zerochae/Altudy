#include <bits/stdc++.h>
using namespace std;

int n, k;

int arr[55][55];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;

        for (int j = 0; j < str.size(); j++)
        {
            if (str[j] == 'Y')
            {

                arr[i][j] = 1;
            }
            else
            {
                arr[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        queue<int> q;
        int sum = 0;

        bool ch[55] = {0};
        ch[i] = 1;
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 1)
            {
                ch[j] = 1;
                sum++;
                q.push(j);
            }
        }

        while (!q.empty())
        {

            int num = q.front();
            // cout << num << "\n";

            q.pop();

            for (int k = 0; k < n; k++)
            {
                if (arr[k][num] == 1 && arr[i][num] == 1 && ch[k] == 0)
                {
                    ch[k] = 1;
                    sum++;
                    // q.push(k);
                }
            }
        }

        // cout << sum << " " << i << "\n";

        ans = max(ans, sum);
    }
    cout << ans;
}
