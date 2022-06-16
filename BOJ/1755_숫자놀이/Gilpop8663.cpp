#include <bits/stdc++.h>
using namespace std;

int n, m;

vector<pair<string, int>> arr;

string nums[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = n; i <= m; i++)
    {
        string str;
        int num, mod;

        if (i < 10)
        {
            arr.push_back({nums[i], i});
        }
        else
        {
            num = i / 10;
            mod = i % 10;
            str = nums[num] + " " + nums[mod];
            arr.push_back({str, i});
        }
    }

    sort(arr.begin(), arr.end());
    int cnt = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i].second << " ";
        cnt++;
        if (cnt == 10)
        {
            cnt = 0;
            cout << "\n";
        }
    }
}
