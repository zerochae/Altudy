#include <bits/stdc++.h>
using namespace std;

string arr[5000005];

int n;

bool comp(string s1, string s2)
{
    return s1 > s2;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    set<string> s;
    for (int i = 0; i < n; i++)
    {
        string name, move;

        cin >> name >> move;
        if (move == "enter")
        {
            s.insert(name);
        }
        else
        {
            s.erase(name);
        }
    }

    // sort(s.begin(), s.end(), comp);

    for (auto iter = s.rbegin(); iter != s.rend(); iter++)
    {
        cout << *iter << "\n";
    }
}
