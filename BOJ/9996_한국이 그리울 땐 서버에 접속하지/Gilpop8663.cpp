#include <bits/stdc++.h>
using namespace std;

int n;

string word;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> word;

    string st;
    string en;

    for (int i = 0; i < word.size(); i++)
    {
        if (word[i] != '*')
        {
            st += word[i];
        }
        else
        {
            break;
        }
    }
    for (int i = word.size() - 1; i >= 0; i--)
    {
        if (word[i] != '*')
        {
            en += word[i];
        }
        else
        {
            break;
        }
    }

    // reverse(en.begin(), en.end());

    // cout << st << " " << en << "\n";

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;

        bool isFind = 0;
        int cnt = 0;
        for (int j = 0; j < st.size(); j++)
        {
            if (st[j] != str[j])
            {
                isFind = 1;
                break;
            }
            else
            {
                cnt++;
            }
        }

        reverse(str.begin(), str.end());
        for (int j = 0; j < en.size(); j++)
        {

            // cout << en[j] << "\n";
            if (en[j] != str[j])
            {
                isFind = 1;
                break;
            }
            else
            {
                cnt++;
            }
        }

        if (isFind == 1 || cnt > str.size())
        {
            cout << "NE"
                 << "\n";
        }
        else
        {
            cout << "DA"
                 << "\n";
        }
    }
}
