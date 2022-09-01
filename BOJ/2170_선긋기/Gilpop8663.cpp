#include <bits/stdc++.h>
using namespace std;

int n;

pair<int, int> arr[1000000];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr, arr + n);

    int sum = 0;
    int start = arr[0].first;
    int end = arr[0].second;
    for (int i = 1; i < n; i++)
    {
        if (arr[i].first <= end)
        {
            end = max(arr[i].second, end);
        }
        else
        {
            sum += end - start;
            start = arr[i].first;
            end = arr[i].second;
        }
    }

    sum += end - start;

    cout << sum;
}
