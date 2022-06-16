#include <bits/stdc++.h>
using namespace std;

int n;

int arr[100005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    vector<int> s;

    for (int i = 0; i < n - 1; i++)
    {
        int num = abs(arr[i] - arr[i + 1]);
        s.push_back(num);
        // cout << num << "\n";
    }

    sort(s.begin(), s.end());

    bool flag = 0;

    int number = gcd(s[0], s[1]);

    long long ans = 0;
    for (int i = 2; i < s.size(); i++)
    {
        number = gcd(number, s[i]);
        // cout << number << "\n";
    }

    for (int i = 0; i < s.size(); i++)
    {
        ans += (s[i] / number) - 1;
    }
    cout << ans;
}
