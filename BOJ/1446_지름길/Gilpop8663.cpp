#include <bits/stdc++.h>
using namespace std;

int n, l;

int d[15];

int st_arr[15];
int en_arr[15];
int dis_arr[15];

int ans;

void func(int k, int cur, int sum)
{
    if (k == n)
    {
        if (cur != l)
        {
            sum += l - cur;
        }
        ans = min(ans, sum);

        // cout << k << " " << cur << " " << sum << "\n";
        return;
    }

    bool isFind = 0;
    for (int i = 0; i < n; i++)
    {
        if (st_arr[i] >= cur && en_arr[i] <= l && dis_arr[i] < en_arr[i] - cur)
        {
            isFind = 1;
            func(k + 1, en_arr[i], sum + dis_arr[i] + st_arr[i] - cur);
        }
    }
    if (isFind == 0)
    {
        func(k + 1, cur, sum);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l;

    for (int i = 0; i < n; i++)
    {
        cin >> st_arr[i] >> en_arr[i] >> dis_arr[i];
    }

    ans = l;

    func(0, 0, 0);

    cout << ans;
}
