#include <bits/stdc++.h>
using namespace std;

int n, m, t;

string str1, str2;

int arr[10005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    cin >> str1 >> str2 >> t;

    reverse(str1.begin(), str1.end());
    vector<char> ch;

    for (int i = 0; i < n; i++)
    {
        ch.push_back('L');
    }

    for (int i = 0; i < m; i++)
    {
        ch.push_back('R');
    }

    string str = str1 + str2;

    for (int i = 0; i < t; i++)
    {

        bool check[n + m + 5] = {0};
        for (int j = 0; j < n + m; j++)
        {
            // cout << str << " " << ch[j] << " " << ch[j + 1] << "\n";
            // cout << check[j] << " " << check[j + 1];
            if (ch[j] == 'L' && ch[j + 1] == 'R' && check[j] == 0 && check[j + 1] == 0)
            {
                check[j] = 1;
                check[j + 1] = 1;
                swap(str[j], str[j + 1]);
                swap(ch[j], ch[j + 1]);
            }
        }
    }

    cout << str;
}
