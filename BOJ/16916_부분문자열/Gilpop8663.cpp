#include <bits/stdc++.h>
using namespace std;

string str1, str2;

set<string> s;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str1 >> str2;

    // char A[] = str1;
    // char b[] = str2;

    char *ans = strstr((char *)str1.c_str(), (char *)str2.c_str());

    if (ans != NULL)
    {
        cout << 1 << "\n";
    }
    else
    {
        cout << 0 << "\n";
    }
}
