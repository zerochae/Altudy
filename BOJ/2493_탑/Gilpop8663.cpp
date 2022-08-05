#include <bits/stdc++.h>
using namespace std;

int n;

stack<pair<int, int>> s;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int height;
        cin >> height;

        while (!s.empty())
        {
            auto cur = s.top();

            if (height < cur.second)
            {
                cout << cur.first << " ";
                break;
            }
            s.pop();
        }

        if (s.empty())
        {
            cout << 0 << " ";
        }

        s.push({i, height});
    }
}
