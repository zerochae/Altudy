#include <bits/stdc++.h>
using namespace std;

int n, m;

char arr[18];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }

    vector<bool> ch;
    for (int i = 0; i < n; i++)
    {
        ch.push_back(0);
    }
    for (int i = 0; i < m - n; i++)
    {
        ch.push_back(1);
    }
    sort(arr, arr + m);

    // for (int i = 0; i < m; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << "\n";

    do
    {
        vector<char> tmp;
        for (int i = 0; i < m; i++)
        {
            if (ch[i] == 0)
            {

                tmp.push_back(arr[i]);
            }
        }

        bool isFind = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (tmp[i] == 'a' || tmp[i] == 'e' || tmp[i] == 'o' || tmp[i] == 'u' || tmp[i] == 'i')
            {
                isFind = 1;
            }
            else
            {
                cnt++;
            }
        }

        if (isFind == 0 || cnt < 2)
            continue;

        for (int i = 0; i < n; i++)
        {
            cout << tmp[i];
        }

        cout << "\n";
    } while (next_permutation(ch.begin(), ch.end()));
}
