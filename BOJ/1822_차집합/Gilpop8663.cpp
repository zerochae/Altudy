#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, m;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    set<int> s;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        s.insert(num);
    }

    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;

        if (s.find(num) != s.end())
        {
            s.erase(num);
        }
    }

    cout << s.size() << "\n";

    for (auto num : s)
    {
        cout << num << " ";
    }
}
