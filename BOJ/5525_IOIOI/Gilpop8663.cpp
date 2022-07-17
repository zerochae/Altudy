#include <bits/stdc++.h>
using namespace std;

string str;

string ioi;

int n, m;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    cin >> str;

    int ans = 0;

    int cnt = 0;

    char arr[2] = {'I', 'O'};

    for (int i = 0; i < m; i++)
    {
        if (str[i] == arr[0] && str[i + 1] == arr[1] && str[i + 2] == arr[0])
        {
            cnt++;
        }
        else if (str[i] == arr[1] && str[i + 1] == arr[0])
            continue;
        else
        {
            if (cnt >= n)
            {
                ans += 1 + (cnt - n);
            }

            cnt = 0;
        }
    }

    // cout << cnt << "\n";

    if (cnt >= n)
    {

        ans += 1 + (cnt - n);
    }

    cout << ans;
}
