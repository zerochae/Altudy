#include <bits/stdc++.h>
using namespace std;

int n;

int maxd[3];

int mind[3];

int arr[3];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    int maxNum = 0, minNum = 1e9;

    cin >> maxd[0] >> maxd[1] >> maxd[2];
    mind[0] = maxd[0];
    mind[1] = maxd[1];
    mind[2] = maxd[2];

    for (int i = 1; i < n; i++)
    {
        cin >> arr[0] >> arr[1] >> arr[2];

        int tmp0 = maxd[0];
        int tmp1 = maxd[1];
        int tmp2 = maxd[2];

        int left = max(tmp0, tmp1);
        int right = max(tmp1, tmp2);

        maxd[0] = left + arr[0];
        maxd[1] = max(left, tmp2) + arr[1];
        maxd[2] = right + arr[2];

        tmp0 = mind[0];
        tmp1 = mind[1];
        tmp2 = mind[2];

        left = min(tmp0, tmp1);
        right = min(tmp1, tmp2);
        mind[0] = left + arr[0];
        mind[1] = min(left, tmp2) + arr[1];
        mind[2] = right + arr[2];
    }

    maxNum = *max_element(maxd, maxd + 3);
    minNum = *min_element(mind, mind + 3);

    cout << maxNum << " " << minNum;
}
