#include <bits/stdc++.h>
using namespace std;

int n;

int arr[1000005];

vector<int> arr2, uni;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        uni.push_back(arr[i]);
    }

    sort(uni.begin(), uni.end());

    uni.erase(unique(uni.begin(), uni.end()), uni.end());

    // for (int i = 0; i < n - 1; i++)
    // {
    //     int num = arr[i];
    //     if (arr[i] != arr[i + 1])
    //     {
    //         arr2.push_back(num);
    //     }
    // }
    // if (arr2.back() != arr[n - 1])
    // {
    //     arr2.push_back(arr[n - 1]);
    // }

    // for (int i = 0; i < arr2.size(); i++)
    // {
    //     // cout << arr2[i] << " ";
    // }

    for (int i = 0; i < n; i++)
    {
        // auto num = binary_search(arr, arr + n, arr[i]);

        cout << lower_bound(uni.begin(), uni.end(), arr[i]) - uni.begin() << " ";
    }
}
