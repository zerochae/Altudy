#include <bits/stdc++.h>
using namespace std;

int arr1[9];

int arr2[9];

vector<int> ans;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 1; i <= 8; i++)
    {
        cin >> arr1[i];
        arr2[i] = arr1[i];
    }

    sort(arr2 + 1, arr2 + 9);
    int sum = 0;
    for (int i = 4; i <= 8; i++)
    {
        sum += arr2[i];
    }

    for (int i = 1; i <= 8; i++)
    {
        for (int j = 4; j <= 8; j++)
        {
            if (arr1[i] == arr2[j])
            {
                ans.push_back(i);
                break;
            }
        }
    }

    sort(ans.begin(), ans.end());

    cout << sum << "\n";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}
