#include <bits/stdc++.h>
using namespace std;

int n, m;

// int arr[10005];

bool ch[10005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int r = 2;

    unordered_map<int, bool> arr;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        arr.insert({num, false});
    }

    int cnt = 0;

    for (auto iter = arr.begin(); iter != arr.end(); iter++)
    {
        if (m - iter->first == iter->first)
            continue;
        if (arr.find(m - iter->first) != arr.end())
        {
            if (iter->second == 1 || arr.find(m - iter->first)->second == 1)
                continue;
            arr.find(m - iter->first)->second = 1;
            iter->second = 1;
            cnt++;
        }
        // cout << iter->first << " " << iter->second << "\n";
    }

    cout << cnt;
}