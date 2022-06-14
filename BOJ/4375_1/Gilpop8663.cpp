#include <bits/stdc++.h>
using namespace std;

int n;

bool check(long long a)
{

    if (a == 1)
        return false;
    string str = to_string(a);

    // cout << str << "\n";
    int cnt = 0;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '1')
        {
            cnt++;
        }
    }
    if (cnt == str.size())
        return true;

    return false;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> n)
    {

        // cout << n << "\n";
        long long num = 0;
        long long first = 1;
        int count = 1;
        while (true)
        {
            first %= n;
            if (first == 0)
            {
                break;
            }

            first = (first * 10) % n + 1;
            count++;
        }
        cout << count << "\n";
    }
    // long long ass = 111111111111;
    // if (check(ass))
    // {
    //     cout << "1로 이루어져있음";
    // }
    // else
    // {
    //     cout << "1로 안 이루어져있음";
    // }
    // cout << check(111) << "\n";
}
