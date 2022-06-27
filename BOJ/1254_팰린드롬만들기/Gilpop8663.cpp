#include <bits/stdc++.h>
using namespace std;

string str;

int n = str.size();

bool isPalin(int idx)
{
    int half = (n - idx) / 2;

    for (int i = 0; i < half; i++)
    {
        // cout << str[idx + i] << " " << str[n - 1 - i] << "\n";
        if (str[idx + i] != str[n - 1 - i])
            return false;
    }

    return true;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;

    n = str.size();

    for (int i = 0; i < n; i++)
    {
        if (isPalin(i) == 1)
        {
            cout << n + i;
            return 0;
        }
    }
}