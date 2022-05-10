#include <bits/stdc++.h>
using namespace std;

int n;

int arr[1000005];

// solution 1
// int main(void)
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     cin >> n;
//     fill(arr, arr + n, 1500005);
//     arr[1] = 0;
//     for (int i = 2; i <= n; i++)
//     {
//         if (i % 3 == 0 && i % 2 == 0)
//         {
//             arr[i] = min(arr[i / 3] + 1, min(arr[i / 2] + 1, arr[i - 1] + 1));
//         }
//         else if (i % 3 == 0)
//         {
//             arr[i] = min(arr[i / 3] + 1, arr[i - 1] + 1);
//         }
//         else if (i % 2 == 0)
//         {
//             arr[i] = min(arr[i / 2] + 1, arr[i - 1] + 1);
//         }
//         else
//         {
//             arr[i] = arr[i - 1] + 1;
//         }
//         // cout << arr[i] << " " << i << "\n";
//     }
//     cout << arr[n];
// }

// solution 2

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    arr[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        arr[i] = arr[i - 1] + 1;
        if (i % 2 == 0)
            arr[i] = min(arr[i], arr[i / 2] + 1);
        if (i % 3 == 0)
            arr[i] = min(arr[i], arr[i / 3] + 1);
    }
    cout << arr[n];
}
