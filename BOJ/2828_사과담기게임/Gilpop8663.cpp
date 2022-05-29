#include <bits/stdc++.h>
using namespace std;

int n, m;

int j;

int arr[12];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    cin >> j;
    int st = 1, end = m;
    arr[m] = 1;

    int ans = 0;
    for (int i = 1; i <= j; i++)
    {
        int num;
        cin >> num;
        if (st <= num && end >= num)
        {
            continue;
        }
        if (abs(st - num) >= abs(end - num))
        {
            ans += abs(end - num);
            end = num;
            st = num - m + 1;
        }
        else
        {
            ans += abs(st - num);
            st = num;
            end = num + m - 1;
        }

        // cout << st << " " << end << "\n";
    }

    cout << ans;
}