#include <bits/stdc++.h>
using namespace std;

int n;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int arr[] = {1, 2, 4, 8, 16, 32, 64};
    int cnt = 0;
    for (int i = 6; i >= 0; i--)
    {
        if (n >= arr[i])
        {
            n -= arr[i];
            cnt++;
        }
    }
    cout << cnt;
}