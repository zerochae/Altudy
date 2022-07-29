#include <bits/stdc++.h>
using namespace std;

int n;

int arr[155];
int d[155];
int ch[300155];

queue<pair<int, int>> q;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    d[1] = 1;
    d[2] = 3;
    d[3] = 6;
    for (int i = 1; i < 150; i++)
    {
        arr[i] = arr[i - 1] + i;
        // cout << arr[i] << " ";
    }

    // cout << "\n";
    fill(ch, ch + 300100, 999999);

    for (int i = 1; i < 150; i++)
    {
        d[i] = d[i - 1] + arr[i];

        if (d[i] <= 300000)
        {
            ch[d[i]] = 1;
        }
        // cout << d[i] << " ";
    }

    int ans = 0;

    ch[0] = 0;
    ch[1] = 1;

    for (int i = 1; i <= n; i++)
    {

        for (int j = 0; j < 150; j++)
        {
            if (i + d[j] > n)
                continue;
            int num = i + d[j];
            ch[num] = min(ch[num], ch[i] + 1);
        }

        // cout << ch[i] << " ";
    }
    cout << ch[n];
}
