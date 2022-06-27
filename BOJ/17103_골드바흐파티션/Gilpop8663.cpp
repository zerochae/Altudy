#include <bits/stdc++.h>
using namespace std;

int t, n;
int number = 1000000;
int arr[1000001];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    vector<int> prime;

    for (int i = 2; i <= 1000000; i++)
    {
        arr[i] = 1;
    }

    for (int i = 2; i <= sqrt(number); i++)
    {
        if (arr[i] == 0)
            continue;
        for (int j = i * i; j <= number; j += i)
        {
            arr[j] = 0;
        }
    }

    while (t--)
    {
        int ch[1000001] = {0};
        map<int, bool> s;
        int ans = 0;

        cin >> n;

        for (int i = 2; i < n; i++)
        {
            // cout << arr[i] << " " << arr[n - i] << "\n";
            if (ch[i] == 1 && ch[n - i] == 1)
                continue;
            if (arr[i] == 1 && arr[n - i] == 1)
            {
                ans++;
                ch[i] = 1;
                ch[n - i] = 1;
            }
        }

        cout << ans << "\n";
    }
}
