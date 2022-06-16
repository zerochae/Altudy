#include <bits/stdc++.h>
using namespace std;

int t, n;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n;
        int arr[1005];
        bool ch[1005] = {0};

        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }

        queue<int> q;

        int ans = 0;

        for (int i = 1; i <= n; i++)
        {
            int num = i;
            if (ch[i] == 0)
            {
                q.push(arr[i]);
                ch[i] == 1;
            }

            bool isCycle = 0;

            while (!q.empty())
            {

                int number = q.front();
                // cout << number << " " << arr[number] << "\n";
                q.pop();

                if (arr[number] == num || number == arr[number])
                {
                    isCycle = 1;
                }
                if (ch[number] == 0)
                {
                    q.push(arr[number]);
                    ch[number] = 1;
                }
            }

            if (isCycle == 1)
            {
                ans++;
            }
        }

        cout << ans << "\n";
    }
}
