#include <bits/stdc++.h>
using namespace std;

int t;
string str;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;

    for (int i = 0; i < str.size(); i++)
    {
        // cout << i << "\n";
        if (str[i] == 'p' && str[i + 1] == 'i')
        {
            i++;
            continue;
        }
        if (str[i] == 'k' && str[i + 1] == 'a')
        {
            i++;
            continue;
        }
        if (str[i] == 'c' && str[i + 1] == 'h' && str[i + 2] == 'u')
        {
            i += 2;
            continue;
        }

        cout << "NO";
        return 0;
    }

    cout << "YES";
}
