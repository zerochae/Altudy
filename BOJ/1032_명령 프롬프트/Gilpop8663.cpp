#include <bits/stdc++.h>
using namespace std;

int n;

string arr[55];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    string ans;

    int len = arr[0].size();

    for (int i = 0; i < len; i++)
    {
        char tmp = arr[0][i];
        bool isFind = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j][i] == tmp)
            {
                continue;
            }
            else
            {
                isFind = 1;
                ans += '?';
                break;
            }
        }
        if (isFind == 0)
        {
            ans += tmp;
        }
    }

    cout << ans;
}
