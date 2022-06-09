#include <bits/stdc++.h>
using namespace std;

int n;

pair<int, int> arr[5005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int num, color;
        cin >> num >> color;
        arr[i] = {color, num};
    }

    sort(arr, arr + n);
    long long sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (i == 0 || arr[i - 1].first != arr[i].first)
        {
            sum += abs(arr[i + 1].second - arr[i].second);
        }
        else if (i == n - 1 || arr[i].first != arr[i + 1].first)
        {
            sum += abs(arr[i].second - arr[i - 1].second);
        }
        else
        {
            sum += min(abs(arr[i].second - arr[i - 1].second), abs(arr[i].second - arr[i + 1].second));
        }
    }

    cout << sum;
}
