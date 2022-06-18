#include <bits/stdc++.h>
using namespace std;

int n;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    priority_queue<int> q;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        if (num == 0)
        {
            if (q.size() > 0)
            {
                cout << -1 * q.top() << "\n";
                q.pop();
            }
            else
            {
                cout << 0 << "\n";
            }
        }
        else
        {
            q.push(-1 * num);
        }
    }
}
