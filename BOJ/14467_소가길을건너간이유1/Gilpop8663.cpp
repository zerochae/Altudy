#include <bits/stdc++.h>
using namespace std;

int n;

int arr[105][2];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b;

        cin >> a >> b;
        if (b == 1)
        {
            if (arr[a][b - 1] == 1)
            {
                cnt++;
            }
            arr[a][b - 1] = 0;
            arr[a][b] = 1;
        }

        if (b == 0)
        {
            if (arr[a][b + 1] == 1)
            {
                cnt++;
            }
            arr[a][b + 1] = 0;
            arr[a][b] = 1;
        }
    }

    cout << cnt;
}