#include <bits/stdc++.h>
using namespace std;

int n, k;

int arr[105];

long long d[105][21];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    int target = arr[n];

    // 초기값

    d[1][arr[1]] = 1; //가장 처음의 수는 무조건 들어감

    for (int i = 2; i <= n - 1; i++)
    {
        for (int j = 0; j <= 20; j++)
        {
            if (d[i - 1][j] == 0)
                continue; //해당 값이 없다면 넘어감

            //현재 위치의 값을 더해서 범위 안에 있다면 경우의 수에 들어감

            if (j + arr[i] <= 20)
            {
                d[i][j + arr[i]] += d[i - 1][j];
            }

            if (j - arr[i] >= 0)
            {
                d[i][j - arr[i]] += d[i - 1][j];
            }
        }
    }

    long long ans = d[n - 1][target];

    cout << ans;

    return 0;
}
