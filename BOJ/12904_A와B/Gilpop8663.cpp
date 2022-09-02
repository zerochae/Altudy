#include <bits/stdc++.h>
using namespace std;

string s;
string t;

bool ans = 0;

void func(string str)
{
    if (str.size() == s.size())
    {
        if (str == s)
        {
            ans = 1;
        }
        return;
    }
    char tmp = str.back();
    str.erase(str.size() - 1);
    if (tmp == 'A')
    {
        func(str);
    }
    else if (tmp == 'B')
    {
        reverse(str.begin(), str.end());
        func(str);
    }
    return;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s >> t;

    func(t);

    cout << ans;

    return 0;
}
