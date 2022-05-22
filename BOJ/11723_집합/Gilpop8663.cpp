#include <bits/stdc++.h>
using namespace std;

int n;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    set<int> s;
    for (int i = 0; i < n; i++)
    {
        string a;
        int num = 0;
        cin >> a;

        if (a != "all" && a != "empty")
        {
            cin >> num;
        }

        if (a == "add")
        {
            s.insert(num);
        }
        if (a == "remove")
        {
            s.erase(num);
        }

        if (a == "check")
        {

            if (s.find(num) != s.end())
            {
                cout << 1 << "\n";
            }
            else
            {
                cout << 0 << "\n";
            }
        }

        if (a == "toggle")
        {
            if (s.find(num) != s.end())
            {
                s.erase(num);
            }
            else
            {
                s.insert(num);
            }
        }

        if (a == "all")
        {
            s = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
        }

        if (a == "empty")
        {
            s.clear();
        }
    }
}