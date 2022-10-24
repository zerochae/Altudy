#include <bits/stdc++.h>
using namespace std;

int n;

int arr[100005];

priority_queue<int, vector<int>, greater<int>> q;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];

        q.push(arr[i]);
    }

    int ans = 0;
    while (q.size() > 1)
    {
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();

        ans += a + b;
        q.push(a + b);
    }

    cout << ans;
}
