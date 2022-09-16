#include <bits/stdc++.h>
using namespace std;

long long n;

int arr[6];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    long long answer = 0;
    int maxNum = 0;

    for (int i = 0; i < 6; i++)
    {
        cin >> arr[i];
        answer += arr[i];
        maxNum = max(arr[i], maxNum);
    }

    if (n == 1)
    {
        cout << answer - maxNum;
    }
    else
    {
        answer = 0;
        arr[0] = min(arr[0], arr[5]);
        arr[1] = min(arr[1], arr[4]);
        arr[2] = min(arr[2], arr[3]);

        sort(arr, arr + 3);

        int sum1 = arr[0];
        int sum2 = arr[1] + sum1;
        int sum3 = arr[2] + sum2;

        answer += sum3 * 4;
        answer += sum2 * (4 * (n - 2) + 4 * (n - 1));
        answer += sum1 * (4 * (n - 1) * (n - 2) + (n - 2) * (n - 2));

        cout << answer;
    }
}
