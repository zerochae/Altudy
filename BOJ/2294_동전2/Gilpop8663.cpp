#include <bits/stdc++.h>
using namespace std;

int n, k;

int d[10005];

int arr[10005];

int main(void)
{

    /*
        1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
    1   1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
    5   0 0 0 0 1 1 1 1 1 2  2  2  2  2 2
    12  0 0 0 0 0 0 0 0 0 0  0  1  1  1  1
    d   1 2 3 4 1 2 3 4


    */

    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    fill(d, d + 10005, 100005);
    d[0] = 0; // 0원 : 0개
    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i]; j <= k; j++)
        {
            //동전 하나 추가한 것과 기존 값 중 작은 값
            d[j] = min(d[j], d[j - arr[i]] + 1);
        }
    }

    // for (int i = 1; i <= k; i++)
    // {

    //     cout << d[i] << " ";
    // }
    cout << (d[k] == 100005 ? -1 : d[k]);
}
