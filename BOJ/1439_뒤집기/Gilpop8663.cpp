#include <bits/stdc++.h>
using namespace std;

string n;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int zeroCnt = 0;
    int oneCnt = 0;
    if (n[n.size() - 1] == '0')
    {
        n += '1';
    }
    else
    {
        n += '0';
    }

    // cout << n;
    for (int i = 0; i < n.size() - 1; i++)
    {
        if (n[i] != n[i + 1] && n[i] == '0')
        {
            zeroCnt++;
        }
        if (n[i] != n[i + 1] && n[i] == '1')
        {
            oneCnt++;
        }
    }

    // cout << zeroCnt << " " << oneCnt << "\n";
    if (zeroCnt > 0 && oneCnt > 0)
    {
        cout << min(zeroCnt, oneCnt);
    }
    if (zeroCnt > 0 && oneCnt == 0)
    {
        if (zeroCnt == 1)
        {
            cout << 0;
        }
        else
        {
            cout << zeroCnt;
        }
    }
    if (oneCnt > 0 && zeroCnt == 0)
    {
        if (oneCnt == 1)
        {
            cout << 0;
        }
        else
        {

            cout << oneCnt;
        }
    }
    if (oneCnt == 0 && zeroCnt == 0)
    {
        cout << 0;
    }
}
