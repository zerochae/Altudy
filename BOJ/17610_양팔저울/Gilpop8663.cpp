#include <bits/stdc++.h>
using namespace std;

int n;

int arr[15];

set<int> s;

int func()
{

    int ans = 0;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    for (int i = 1; i <= sum; i++)
    {
        if (s.find(i) == s.end())
        {
            // cout << i << " ";
            ans++;
        }
    }
    return ans;
}

void DFS(int k, int sum)
{
    if (k == n)
    {
        if (sum < 1)
            return;
        // cout << sum << "\n";
        s.insert(sum);
        return;
    }

    DFS(k + 1, sum);
    DFS(k + 1, sum + arr[k]);
    DFS(k + 1, sum - arr[k]);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    DFS(0, 0);

    cout << func();
}
