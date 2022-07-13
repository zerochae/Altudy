#include <bits/stdc++.h>
using namespace std;

int n, m;

int idxFunc(string str)
{

    int idx = -5;
    int len = str.size();
    for (int i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - 1 - i])
        {
            idx = i;
            return idx;
        }
    }
    return idx;
}

bool func(string str)
{

    int len = str.size();
    for (int i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - 1 - i])
        {
            return false;
        }
    }
    return true;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    while (n--)
    {
        string s1;
        string s2;

        cin >> s1;

        s2 = s1;

        int idx = idxFunc(s1);
        int idx2 = s1.length() - 1 - idx;
        if (idx == -5)
        {
            cout << 0 << "\n";
            continue;
        }

        s1.erase(idx, 1);
        s2.erase(idx2, 1);

        bool ch = 0;
        int ch1 = 0;
        int ch2 = 0;

        if (func(s1) == 0)
        {
            ch1++;
        }

        if (func(s2) == 0)
        {
            ch2++;
        }

        if (ch1 + ch2 == 2)
        {
            ch = 1;
        }

        if (!ch)
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << 2 << "\n";
        }
    }
}