#include <bits/stdc++.h>
using namespace std;

int n;
// 2000000000
int d[100005][4];

int arr[100005][4];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int test = 0;

    while (true)
    {

        cin >> n;
        if (n == 0)
            break;
        test++;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cin >> arr[i][j];
            }
        }

        d[0][0] = 100000000;
        d[0][1] = arr[0][1];
        d[0][2] = d[0][1] + arr[0][2];
        for (int i = 1; i < n; i++)
        {

            d[i][0] = min(d[i - 1][0], d[i - 1][1]) + arr[i][0];
            d[i][1] = min({d[i - 1][0], d[i - 1][1], d[i - 1][2]}) + arr[i][1];
            d[i][1] = min(d[i][0] + arr[i][1], d[i][1]);
            d[i][2] = min(d[i - 1][1], d[i - 1][2]) + arr[i][2];
            d[i][2] = min(d[i][1] + arr[i][2], d[i][2]);
        }

        // for (int i = 0; i < n; i++)
        // {

        //     cout << d[i][0] << " " << d[i][1] << " " << d[i][2] << "\n";
        // }
        // cout << "먼데";
        cout << test << "."
             << " " << d[n - 1][1] << "\n";
    }
}
