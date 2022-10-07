#include <bits/stdc++.h>
using namespace std;

int n;

int arr[80005];

stack<int> s;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    long long ans = 0;

    for (int i = 0; i < n; i++)
    {

        while (!s.empty() && s.top() <= arr[i])
        {
            s.pop();
        }

        ans += (long long)s.size();
        s.push(arr[i]);
    }

    cout << ans;
}
