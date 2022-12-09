#include <bits/stdc++.h>
using namespace std;

int n;

string arr[22];
string copy_arr[22];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        copy_arr[i] = arr[i];
    }

    sort(copy_arr, copy_arr + n);

    bool isInc = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != copy_arr[i])
        {
            isInc = 0;
            break;
        }
    }

    if (isInc == 1)
    {
        cout << "INCREASING";
        return 0;
    }

    sort(copy_arr, copy_arr + n, greater<>());

    bool isDec = 1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] != copy_arr[i])
        {
            isDec = 0;
            break;
        }
    }

    if (isDec == 1)
    {
        cout << "DECREASING";
    }
    else
    {
        cout << "NEITHER";
    }
}
