#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[1005];

priority_queue<long long, vector<long long>, greater<long long>> q;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        q.push(num);
    }

    while (m--)
    {
        long long num = q.top();
        q.pop();
        long long num2 = q.top();
        q.pop();

        long long k = num + num2;

        q.push(k);
        q.push(k);

        // cout << num << " ";
    }

    long long ans = 0;

    while (!q.empty())
    {
        long long num = q.top();
        q.pop();

        ans += num;
    }

    cout << ans;
}
