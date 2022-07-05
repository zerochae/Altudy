#include <bits/stdc++.h>
using namespace std;

int t, n;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

vector<int> ans;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while (t--)
    {
        int num;

        cin >> num;

        if (num != 0)
        {
            q.push({abs(num), num});
        }

        if (num == 0)
        {
            if (q.size() > 0)
            {

                pair<int, int> cur = q.top();
                q.pop();

                cout << cur.second << "\n";
            }
            else
            {
                cout << 0 << "\n";
            }
        }
    }

    //     while (!q.empty())
    //     {

    //         pair<int, int> cur = q.top();
    //         q.pop();

    //         cout << cur.first << " " << cur.second << "\n";
    //     }
}