#include <bits/stdc++.h>
using namespace std;

using ll = long long;

string n;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int arr[n.size()];
    int sum = 0;

    bool flag = false;
    for (int i = 0; i < n.size(); i++)
    {
        arr[i] = n[i] - '0';
        sum += arr[i];
        if (arr[i] == 0)
        {
            flag = true;
        }
        // cout << arr[i] << "\n";
    }

    if (sum % 3 != 0 || !flag)
    {
        cout << -1;
        return 0;
    }

    sort(arr, arr + n.size());
    reverse(arr, arr + n.size());

    for (int i = 0; i < n.size(); i++)

    {
        cout << arr[i];
    }
}
