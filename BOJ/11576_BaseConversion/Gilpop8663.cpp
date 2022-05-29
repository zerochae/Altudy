#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int A, B;

int t;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> B;

    cin >> t;

    ll sum = 0;

    for (int i = 0; i < t; i++)
    {
        ll num;
        ll pow = 1;
        cin >> num;

        // sum += num;
        for (int j = t - i - 1; j > 0; j--)
        {
            pow *= A;
        }
        // cout << pow << "\n";
        sum += pow * num;
    }
    // cout << sum << "\n";
    // 4 100
    ll ans = 0;

    vector<int> arr;

    while (sum > 0)
    {
        arr.push_back(sum % B);
        sum /= B;
    }

    reverse(arr.begin(), arr.end());

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}
