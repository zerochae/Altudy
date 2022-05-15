#include <bits/stdc++.h>
using namespace std;

int n, m;
// 2000000000
int d[45];

int arr[45];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        cin >> arr[i];
    }
    arr[m + 1] = n + 1;

    d[0] = 1;
    d[1] = 1;
    d[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        d[i] = d[i - 1] + d[i - 2];
    }

    int ans = 1;
    // for (int i = 1; i < m; i++)
    // {
    //     ans *= d[arr[i] - arr[i - 1] - 1];
    //     cout << ans << " " << d[arr[i] - arr[i - 1] - 1] << "\n";
    // }

    // for (int i = 0; i < m; i++)
    // {

    // }

    for (int i = 1; i <= m + 1; i++)
    {
        ans *= d[arr[i] - arr[i - 1] - 1]; // arr[1] - arr[0] - 1 = 4 - 0 - 1
        // arr[2] -arr[1] -1 = 7 - 4 -1 = 2
        // arr[3] - arr[2] - 1 =  10 - 7  -1 = 2
    }

    cout << ans;
    // cout << d[n] << " " << d[3] << " " << d[2] << " " << d[2] << "\n";

    // d[1] = 1, 2; // i ,
    // d[2] = 2, 1; // i , i-1
    // d[3] = 3, 2; // 마지막에는 i 가 앉거나 i-1이 앉아야 함
}
