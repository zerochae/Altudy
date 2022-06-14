#include <bits/stdc++.h>
using namespace std;

int n, k;

int arr[1005];

bool ch[1005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    int ans = 0;
    int number = 0;
    bool isCheck = 0;
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        if (ch[i] == 1)
            continue;
        int num = arr[i] + k;
        int cnt = 1;
        ch[i] = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (num > arr[j])
            {

                ch[j] = 1;
            }
            else
            {
                break;
            }
        }

        ans += cnt;
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << ch[i] << " ";
    // }

    cout << ans;
}
