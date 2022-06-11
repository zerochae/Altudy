#include <bits/stdc++.h>
using namespace std;

int t, n;

char str[1005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;

    while (t--)
    {
        vector<string> s;
        cin >> n;
        string word;
        int num;
        for (int i = 0; i < n; i++)
        {

            cin >> str[i];
            // cout << str[i] << " " << num << " " << str[i] - '0' << "\n";
            if (i == 0)
            {
                word = str[i];
                num = str[i] - '0';
            }
            else if (num < str[i] - '0')
            {
                word = word + str[i];
            }
            else if (num >= str[i] - '0')
            {
                if (word[0] - '0' < str[i] - '0')
                {
                    word = word + str[i];
                }
                else
                {
                    word = str[i] + word;
                }
            }
        }

        cout << word;

        cout
            << "\n";
    }
}
