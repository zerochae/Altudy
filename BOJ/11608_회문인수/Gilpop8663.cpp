#include <bits/stdc++.h>
using namespace std;

int t;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int num;
        cin >> num;

        bool flag = 0;
        for (int j = 2; j <= 64; j++)
        {
            int n = num;
            vector<int> s;
            if (flag == 1)
            {
                break;
            }
            while (n != 0)
            {
                s.push_back(n % j);
                n /= j;
            }

            for (int k = 0; k < s.size() / 2; k++)
            {
                // cout << s[k] << " ";
                if (s[k] != s[s.size() - 1 - k])
                {
                    flag = 0;
                    break;
                }
                else
                {
                    flag = 1;
                }
            }
        }
        if (flag == 0)
        {
            cout << "0";
        }
        else
        {
            cout << "1";
        }
        cout << "\n";
    }
}
