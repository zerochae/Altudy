#include <bits/stdc++.h>
using namespace std;

int t, n, m;

string arr[10005];

bool isCall()
{
    for (int i = 0; i < n - 1; i++)
    {
        int cur = arr[i].size();
        int next = arr[i + 1].size();
        if (cur >= next)
            continue;
        if (arr[i + 1].substr(0, cur) == arr[i])
        {
            return true;
        }
    }
    return false;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--)
    {
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        sort(arr, arr + n);

        if (isCall())
        {
            cout << "NO"
                 << "\n";
        }
        else
        {
            cout << "YES"
                 << "\n";
        }
    }
}
