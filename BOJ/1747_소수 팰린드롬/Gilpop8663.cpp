#include <bits/stdc++.h>
using namespace std;

int n;

bool ch[1100005] = {0};

int M = 1100002;

vector<int> prime;

bool func(int k)
{
    string str;

    str = to_string(k);

    int n = str.size();
    for (int i = 0; i < n / 2; i++)
    {
        if (str[i] != str[n - i - 1])
        {
            return false;
        }
    }
    return true;
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    // fill(ch, ch + M, 0);
    for (int i = 2; i < M; i++)
    {
        if (ch[i] == 1)
            continue;
        prime.push_back(i);
        for (int j = i * 2; j < M; j += i)
        {
            ch[j] = 1;
        }
    }

    for (auto x : prime)
    {
        if (x >= n)
        {
            if (func(x))
            {
                cout << x;
                return 0;
            }
        }
        // cout << x << " ";
    }
}
