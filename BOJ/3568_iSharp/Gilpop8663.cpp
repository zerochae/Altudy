#include <bits/stdc++.h>
using namespace std;

string str;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    getline(cin, str);

    int n = str.size();

    string base;

    // 기본 변수형

    for (int i = 0; i < n; i++)
    {

        string tmp;
        if (str[i] == ' ')
        {

            for (int j = i + 1; j < n; j++)
            {
                tmp += str[j];
            }
            str = tmp;
            break;
        }
        else
        {
            base += str[i];
        }
    }

    string name, type;

    for (int i = 0; i < str.size();)
    {
        if (str[i] == ',' || str[i] == ';')
        {
            string r_type = "";

            for (int j = type.size() - 1; j >= 0; j--)
            {
                if (type[j] == '[')
                {
                    r_type += ']';
                }
                else if (type[j] == ']')
                {
                    r_type += '[';
                }
                else
                {
                    r_type += type[j];
                }
            }

            cout << base << r_type << " " << name << ';' << "\n";

            name = "";
            type = "";

            if (str[i] == ';')
                break;
            else
                i += 2;
        }
        else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
        {
            name += str[i];
            i++;
        }
        else
        {
            type += str[i];
            i++;
        }
    }

    // cout << str << " " << base << "\n";
}
