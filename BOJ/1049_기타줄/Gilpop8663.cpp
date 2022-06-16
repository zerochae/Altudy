#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr1[60];
int arr2[60];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int pack, one;

        cin >> arr1[i] >> arr2[i];
    }

    sort(arr1, arr1 + m);
    sort(arr2, arr2 + m);

    if (arr2[0] * 6 < arr1[0])
    {
        cout << arr2[0] * n;
        return 0;
    }
    int ans = 0;
    ans = n / 6 * arr1[0];
    n %= 6;

    ans += min(arr2[0] * n, arr1[0]);

    cout << ans;
}
