#include <bits/stdc++.h>
using namespace std;

int n;

vector<pair<int, int>> arr;
priority_queue<int, vector<int>, greater<int>> pq;

int MOD = 1000000000;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int num1, num2;
        cin >> num1 >> num2;

        arr.push_back({num1, num2});
    }

    sort(arr.begin(), arr.end());

    pq.push(arr[0].second);

    for (int i = 1; i < n; i++)
    {
        int num = pq.top();
        if (num <= arr[i].first)
        {
            pq.pop();
            pq.push(arr[i].second);
        }
        else
        {
            pq.push(arr[i].second);
        }
    }

    cout << pq.size();
}
