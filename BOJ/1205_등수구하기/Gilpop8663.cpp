#include <bits/stdc++.h>
using namespace std;

int n, score, p;

vector<pair<int, int>> arr;

bool comp(pair<int, int> a, pair<int, int> b)
{
    if (a.first != b.first)
    {
        return a.first > b.first;
    }
    else
    {
        return a.second < b.second;
    }
}

int nums[55];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> score >> p;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        int cnt = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i].first == num)
            {
                cnt++;
            }
        }

        arr.push_back({num, cnt});
    }

    int scoreNums = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i].first == score)
        {
            scoreNums++;
        }
    }

    arr.push_back({score, scoreNums});
    sort(arr.begin(), arr.end(), comp);

    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i].first == score && scoreNums == arr[i].second)
        {
            ans = i + 1;
        }
    }

    if (ans > p)
    {
        cout << -1;
    }
    else
    {
        ans -= scoreNums;
        cout << ans;
    }
}
