#include <bits/stdc++.h>
using namespace std;

int n, kkk;

int arr[10];

int ans = 0;

int newArr[10];

bool isused[10];

bool comp(int a, int b)
{
    return a > b;
}

void func(int k)
{
    if (k == n)
    {
        // for (int i = 0; i < n; i++)
        // {
        //     cout << newArr[i] << " ";
        // }
        // cout << "\n";

        int sum = 0;

        for (int j = 0; j < n; j++)
        {
            sum += newArr[j] - kkk;

            if (sum < 0)
                break;
        }

        if (sum >= 0)
        {
            ans++;
        }
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!isused[i])
        {
            newArr[k] = arr[i];
            isused[i] = 1;
            func(k + 1);
            isused[i] = 0;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> kkk;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    func(0);

    cout << ans;
}
