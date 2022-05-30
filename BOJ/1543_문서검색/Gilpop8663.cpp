#include <bits/stdc++.h>
using namespace std;

string a, b;

map<string, int> s;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    getline(cin, a);
    getline(cin, b);

    int n = a.size();
    int m = b.size();

    int cnt = 0;
    for (int i = 0; i <= n; i++)

    {
        string str;
        str = a.substr(i);

        // cout << str << " " << str.find(b) << " " << m << " " << i << "\n";
        if (str.find(b) < 3000)
        {
            i += str.find(b) + m - 1;
        }
        else
        {
            cout << cnt;
            break;
        }
        cnt++;
        // cout << str << " " << str.find(b) << "\n";
    }
}
