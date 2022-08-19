#include <bits/stdc++.h>
using namespace std;

int n;

int arr[100005];

int answer[2];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int st = 0;
    int en = n - 1;

    int min = 2e9;

    while (st < en)
    {
        int sum = arr[st] + arr[en];

        if (min > abs(sum))
        {
            min = abs(sum);
            answer[0] = arr[st];
            answer[1] = arr[en];

            if (sum == 0)
                break;
        }

        if (sum < 0)
        {
            st++;
        }
        else
        {
            en--;
        }
    }

    cout << answer[0] << " " << answer[1];
}
