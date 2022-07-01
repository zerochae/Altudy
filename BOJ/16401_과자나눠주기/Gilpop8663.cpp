#include <bits/stdc++.h>
using namespace std;

int m, n;

int arr[1000005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;

    int sumNum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sumNum += arr[i];
    }

    if (m > sumNum)
    {
        cout << 0;
        return 0;
    }
    else if (m == sumNum)
    {
        cout << 1;
        return 0;
    }

    long long low = 0;

    long long high = 1e11;
    long long ans = 0;

    while (low <= high)
    {

        long long mid = (low + high) / 2;

        long long sum = 0;
        for (long long i = 0; i < n; i++)
        {
            sum += arr[i] / mid;
        }

        if (sum >= m)
        {
            low = mid + 1;
            ans = mid;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << ans;
}
