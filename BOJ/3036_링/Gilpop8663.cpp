#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[10005];

// int gcd(int a, int b)
// {
//     int c;
//     while (b != 0)
//     {
//         int a = b;
//         b = a % b;
//         c = b;
//     }
// }

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i < n; i++)
    {
        // cout << gcd(arr[i], arr[0]) << "\n";
        int num = gcd(arr[i], arr[0]);

        cout << arr[0] / num << "/" << arr[i] / num << "\n";
    }
}
