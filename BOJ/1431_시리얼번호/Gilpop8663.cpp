#include <bits/stdc++.h>
#include <cmath>
using namespace std;

string arr[60];

bool cmp(string a, string b)
{

    if (a.size() != b.size())
    {
        return a.size() < b.size();
    }
    int tmp1 = 0;
    int tmp2 = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (isdigit(a[i]))
            tmp1 += a[i] - '0';
        if (isdigit(b[i]))
            tmp2 += b[i] - '0';
        // cout << a[i] << " " << b[i] << "\n";
    }
    // cout << tmp1 << " " << tmp2 << "\n";
    if ((tmp1 == 0 && tmp2 == 0) || tmp1 == tmp2)
    {
        return a < b;
    }
    else
    {
        return tmp1 < tmp2;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        // cout << arr[i] << "\n";
    }
    sort(arr, arr + n, cmp);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\n";
    }
}
