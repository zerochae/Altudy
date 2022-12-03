#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;

    while (getline(cin, str))
    {
        if (str == "END")
        {
            break;
        }

        reverse(str.begin(), str.end());

        cout
            << str << "\n";
    }
}
