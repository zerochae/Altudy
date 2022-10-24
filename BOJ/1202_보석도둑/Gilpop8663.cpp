#include <bits/stdc++.h>
using namespace std;

int n, k;

vector<pair<int, int>> arr;

multiset<int> bag;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        int num, num2;
        cin >> num >> num2;
        arr.push_back({num2, num});
    }
    sort(arr.begin(), arr.end());

    for (int i = 0; i < k; i++)
    {
        int num;
        cin >> num;
        bag.insert(num);
    }

    long long ans = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        auto cur = arr[i];

        auto it = bag.lower_bound(cur.second);

        if (it == bag.end())
            continue;
        ans += cur.first;

        bag.erase(it);
    }

    cout << ans;
}
