#include <bits/stdc++.h>
using namespace std;

int n, m;

map<int, int> arr;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        int num;

        cin >> num;

        arr.insert({num, 1});
    }

    int cnt = 0;

    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;

        if (arr.find(num) != arr.end())
        {
            cnt++;
        }
    }

    int ans = n + m - cnt * 2;

    cout << ans;
}
