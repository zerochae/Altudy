#include <bits/stdc++.h>
using namespace std;

int n, m;
// 2000000000
int d[45];

int arr[1000];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++)
    {

        int sum = 0;
        int nums[6];
        for (int j = 0; j < 5; j++)
        {
            cin >> nums[j];
        }
        vector<int> ans;
        for (int i = 0; i < 3; i++)
        {
            for (int j = i + 1; j < 4; j++)
            {
                for (int k = j + 1; k < 5; k++)
                {
                    ans.push_back((nums[i] + nums[j] + nums[k]) % 10);
                    // cout << (nums[i] + nums[j] + nums[k]) % 10 << "\n";
                }
            }
        }

        sort(ans.begin(), ans.end());
        arr[i] = ans[ans.size() - 1];
    }

    int ansNum = 0;
    int maxNum = 0;
    for (int i = 0; i < n; i++)
    {
        if (maxNum <= arr[i])
        {
            maxNum = arr[i];
            ansNum = i + 1;
        }
        // cout << arr[i] << "\n";
    }

    cout << ansNum;
}
