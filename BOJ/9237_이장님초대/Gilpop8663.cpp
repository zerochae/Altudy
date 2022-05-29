#include <bits/stdc++.h>
using namespace std;

int n;

int arr[100005];

bool comp(int a, int b)
{
    return a > b;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n, comp);

    int maxNum = 0;
    for (int i = 0; i < n; i++)
    {
        maxNum = max(maxNum, arr[i] + i);
    }

    cout << maxNum + 2;
}