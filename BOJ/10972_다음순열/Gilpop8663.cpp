#include <bits/stdc++.h>
using namespace std;

int n;

int arr[10005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int sortCnt = 0;
    int cnt = 2;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] >= arr[i + 1])
        {
            sortCnt++;
        }
    }

    if (sortCnt == n - 1)
    {
        cout << -1;
        return 0;
    }

    do
    {
        if (cnt == 0)
            break;

        if (cnt == 1)
        {
            for (int i = 0; i < n; i++)
            {
                cout << arr[i] << " ";
            }
        }
        cnt--;

    } while (next_permutation(arr, arr + n));
}
