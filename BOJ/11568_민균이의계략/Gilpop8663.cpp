#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[1005];
int d[1005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        d[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                d[i] = max(d[i], d[j] + 1);
            }
        }
        // cout << d[i] << " ";
    }

    cout << *max_element(d, d + n);
}
