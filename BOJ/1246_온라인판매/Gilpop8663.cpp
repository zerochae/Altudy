#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[1005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + m);

    int maxNum = 0;
    int number = 0;
    for (int i = 0; i < m; i++)
    {
        int eggs = min(n, m - i);
        int num = arr[i] * eggs;
        if (maxNum < num)
        {
            number = arr[i];
            maxNum = num;
        }
        // cout << num << "\n";
    }

    cout << number << " " << maxNum;
}
