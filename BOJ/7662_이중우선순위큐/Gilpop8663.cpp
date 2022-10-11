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

        multiset<int> s;
        for (int i = 0; i < n; i++)
        {
            char str;
            int num;

            cin >> str >> num;

            if (str == 'I')
            {
                s.insert(num);
            }
            else
            {
                if (s.empty())
                    continue;
                if (num == -1)
                {
                    auto iter = s.begin();
                    s.erase(iter);
                }
                else
                {
                    auto iter = s.end();
                    s.erase(prev(iter));
                }
            }
        }

        auto maxIter = s.end();
        auto minIter = s.begin();

        if (s.empty())
        {
            cout << "EMPTY"
                 << "\n";
        }
        else
        {
            cout << *prev(maxIter) << " " << *minIter << "\n";
        }
    }
}
