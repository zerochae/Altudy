#include <bits/stdc++.h>
using namespace std;

int n;

int ans = 1e9;

pair<int, int> arr[12];

void func(int index, int curS, int curB)
{

    if (index == n)
    {
        ans = min(ans, abs(curS - curB));
        return;
    }

    int diff = abs(curS - curB);

    ans = min(diff, ans);

    if (diff > 1e11)
    {
        return;
    }

    for (int i = index + 1; i < n; i++)
    {
        func(i, curS * arr[i].first, curB + arr[i].second);
    }
    return;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }

    for (int i = 0; i < n; i++)
    {

        // func(i, 1, 0);
        func(i, arr[i].first, arr[i].second);
    }

    cout << ans << "\n";
}