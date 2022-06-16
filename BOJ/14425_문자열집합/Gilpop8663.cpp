#include <bits/stdc++.h>
using namespace std;

int n, m;

map<string, int> arr;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        arr.insert({str, 1});
    }

    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        string str;
        cin >> str;
        if (arr.find(str) != arr.end())
        {
            ans++;
        }
    }

    cout << ans;
}
