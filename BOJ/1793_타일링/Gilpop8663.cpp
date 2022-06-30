#include <bits/stdc++.h>
using namespace std;

int n;

string d[255];

string sum(string a, string b)
{
    int sum = 0;
    string result;

    while (!a.empty() || !b.empty() || sum)
    {
        if (!a.empty())
        {
            sum += a.back() - '0';
            a.pop_back();
        }

        if (!b.empty())
        {
            sum += b.back() - '0';
            b.pop_back();
        }

        result.push_back((sum % 10) + '0');
        sum /= 10;
    }

    reverse(result.begin(), result.end());

    return result;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    d[0] = "1";
    d[1] = "1";
    d[2] = "3";
    d[3] = "5";
    d[4] = "11";

    for (int i = 5; i < 251; i++)
    {
        string tmp = sum(d[i - 2], d[i - 2]);
        d[i] = sum(d[i - 1], tmp);
    }
    while (cin >> n)
    {
        cout << d[n] << "\n";
    }
}
