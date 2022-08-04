#include <bits/stdc++.h>
using namespace std;

int n;

vector<pair<int, int>> arr;

int d[100];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int num, num1;
        cin >> num >> num1;
        arr.push_back({num, num1});
    }

    sort(arr.begin(), arr.end());

    fill(d, d + n, 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i].second > arr[j].second)
            {
                d[i] = max(d[i], d[j] + 1);
            }
        }

        // cout << d[i] << " ";
    }

    int maxNum = *max_element(d, d + n);

    int ans = n - maxNum;
    cout << ans;
}
