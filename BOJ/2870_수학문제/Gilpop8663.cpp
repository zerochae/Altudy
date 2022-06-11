#include <bits/stdc++.h>
using namespace std;

int t, n;

bool comp(string a, string b)
{
    if (a.size() != b.size())
    {
        return a.size() < b.size();
    }
    else
    {
        return a < b;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;

    vector<string> s;
    cin.ignore();
    while (t--)
    {

        string str;
        getline(cin, str);

        string number;
        int num;
        for (int i = 0; i < str.size(); i++)
        {
            if (isdigit(str[i]) == 0)
            {
                if (number.size() >= 1)
                {
                    string newNumber;
                    bool flag = 0;
                    for (int i = 0; i < number.size(); i++)
                    {
                        if (number[i] == '0' && flag == 0)
                        {
                            continue;
                        }
                        else
                        {
                            flag = 1;
                            newNumber += number[i];
                        }
                    }
                    if (number.size() >= 1 && number[0] == '0' && flag == 0)
                    {
                        newNumber = '0';
                    }
                    // cout << newNumber << "\n";
                    s.push_back(newNumber);
                    number = "";
                }

                continue;
            }
            number += str[i];

            if (i == str.size() - 1)
            {
                if (number.size() >= 1)
                {
                    string newNumber;
                    bool flag = 0;
                    for (int i = 0; i < number.size(); i++)
                    {
                        if (number[i] == '0' && flag == 0)
                        {
                            continue;
                        }
                        else
                        {
                            flag = 1;
                            newNumber += number[i];
                        }
                    }

                    if (number.size() >= 1 && number[0] == '0' && flag == 0)
                    {
                        newNumber = '0';
                    }

                    // cout << newNumber << "\n";
                    s.push_back(newNumber);
                    number = "";
                }
            }
        }
        // cout << str << "\n";
    }
    sort(s.begin(), s.end(), comp);

    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i] << "\n";
    }
}
