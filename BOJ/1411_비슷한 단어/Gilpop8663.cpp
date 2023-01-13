#include <bits/stdc++.h>
using namespace std;

int n;

string arr[102];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;

        bool ch[55] = {0};
        int tmp[55];
        int idx = 0;

        for (int j = 0; j < str.size(); j++)
        {
            if (ch[j] == 1)
                continue;
            char word = str[j];

            for (int k = j; k < str.size(); k++)
            {
                if (str[k] == word)
                {
                    tmp[k] = idx;
                    ch[k] = 1;
                }
            }
            idx += 1;
        }

        string str2;
        for (int j = 0; j < str.size(); j++)
        {
            string tmppp = to_string(tmp[j]);

            str2 += tmppp;
        }
        arr[i] = str2;
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                ans += 1;
            }
        }
        // cout << arr[i] << "\n";
    }

    cout << ans;
}
