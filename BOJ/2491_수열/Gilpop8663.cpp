#include <bits/stdc++.h>
using namespace std;

int n;

int arr[100005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int up = 0;
    int down = 0;
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            up++;
            down++;
        }
        else if (arr[i] < arr[i + 1])
        {
            up++;
            ans = max(ans, down);
            down = 0;
        }
        else if (arr[i] > arr[i + 1])
        {
            down++;
            ans = max(ans, up);
            up = 0;
        }
    }
    ans = max(ans, max(down, up));
    cout << ans + 1;
}