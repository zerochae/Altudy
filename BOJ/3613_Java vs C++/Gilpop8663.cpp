#include <bits/stdc++.h>
using namespace std;

string str;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;

    int aNum = 'A' - 0;
    int zNum = 'Z' - 0;

    // cout << aNum << " "
    //      << zNum << "\n";

    bool isJava = 0;
    bool isC = 0;

    string ans;

    bool isNext = 0;
    for (int i = 0; i < str.size(); i++)
    {
        char change;

        if (str[i] == '_')
        {
            if (isNext == 1)
            {
                cout << "Error!";
                return 0;
            }
            isNext = 1;
            isC = 1;
        }

        if (str[i] - 0 >= 65 && str[i] - 0 <= 90)
        {
            isNext = 1;
            isJava = 1;
        }

        if (isNext == 0)
        {
            ans += str[i];
        }

        if (isNext == 1 && isC == 1 && str[i] != '_') // 소문자에서 대문자로
        {
            isNext = 0;
            change = toupper(str[i]);
            ans += change;
        }

        if (isNext == 1 && isJava == 1)
        {
            isNext = 0;
            change = tolower(str[i]);
            ans += '_';
            ans += change;
        }

        // cout << ans << "\n";
    }
    if ((isJava == 1 && isC == 1) || (str[0] == '_' || str[0] - 0 >= 65 && str[0] - 0 <= 90) || str[str.size() - 1] == '_')
    {
        cout << "Error!";
    }
    else
    {

        cout << ans;
    }
}
