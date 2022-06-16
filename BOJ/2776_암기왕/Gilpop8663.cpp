#include <bits/stdc++.h>
using namespace std;

int t;

int n, m;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;

    while (t--)
    {
        unordered_map<int, int> arr;

        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            arr.insert({num, 1});
        }

        cin >> m;

        for (int i = 0; i < m; i++)
        {
            int num;
            cin >> num;
            if (arr.find(num) != arr.end())
            {
                int j = arr.find(num)->second;
                cout << j << "\n";
            }
            else
            {
                cout << 0 << "\n";
            }
        }
    }
}
