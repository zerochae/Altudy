#include <bits/stdc++.h>
using namespace std;

int n, m;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        reverse(str.begin(), str.end());
        for (int j = 0; j < m; j++)
        {
            cout << str[j];
        }
        cout << "\n";
    }
}
