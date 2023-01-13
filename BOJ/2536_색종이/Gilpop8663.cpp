#include <bits/stdc++.h>
using namespace std;

int n;

int arr[105][105];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        for (int j = x; j < x + 10; j++)
        {
            for (int k = y; k < y + 10; k++)
            {
                arr[j][k] = 1;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= 100; i++)
    {
        for (int j = 0; j <= 100; j++)
        {

            if (arr[i][j] == 1)
            {
                ans += 1;
            }
        }
    }
    cout << ans;
}
