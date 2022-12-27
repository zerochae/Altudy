#include <bits/stdc++.h>
using namespace std;

string n, m;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    if (n.find(m) == string::npos)
    {

        cout << "no";
    }
    else
    {
        cout << "go";
    }
}
