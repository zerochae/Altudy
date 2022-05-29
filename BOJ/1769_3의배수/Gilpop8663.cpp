#include <bits/stdc++.h>
using namespace std;

string str;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;

    int cnt = 0;
    while (true)
    {
        int sum = 0;
        string newStr;

        if (str.size() == 1)
            break;

        for (int i = 0; i < str.size(); i++)
        {
            sum += str[i] - '0';
        }

        newStr = to_string(sum);

        str = newStr;

        cnt++;
        // cout << str << "\n";
    }

    cout << cnt << "\n";
    if ((str[0] - '0') % 3 == 0)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}
