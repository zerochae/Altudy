#include <bits/stdc++.h>
using namespace std;

int n;

int p[1005];

int arr[1005];
int ori[1005];

bool ch[1005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        arr[i] = {num};
        ori[i] = {num};
    }

    sort(arr, arr + n);

    // 2 3 1

    // 1 2 3

    // 1 2 0

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (ch[j] == 1)
                continue;
            if (arr[j] == ori[i])
            {
                ch[j] = 1;
                // cout << j << " " << arr[i] << " " << ori[j] << "\n";
                cout << j << " ";
                break;
            }
        }
    }
}