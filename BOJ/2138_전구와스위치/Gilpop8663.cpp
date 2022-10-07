#include <bits/stdc++.h>
using namespace std;

int n;

int ans = 1e9;
string str1;
string str2;
string temp;
void lightOn(int k)
{
    if (k > 0)
    {
        temp[k - 1] = (temp[k - 1] == '0') ? '1' : '0';
    }
    temp[k] = (temp[k] == '0') ? '1' : '0';
    if (k < n - 1)
    {
        temp[k + 1] = (temp[k + 1] == '0') ? '1' : '0';
    }
    return;
}

void func(int k)
{
    int cnt = 0;
    temp = str1;
    if (k == 0)
    {
        temp[0] = (temp[0] == '0') ? '1' : '0';
        temp[1] = (temp[1] == '0') ? '1' : '0';
        cnt++;
    }

    for (int i = 1; i < n; i++)
    {
        if (temp[i - 1] != str2[i - 1])
        {
            lightOn(i);
            cnt++;
        }
    }
    if (temp == str2)
    {
        ans = min(ans, cnt);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    cin >> str1 >> str2;

    func(0);
    func(1);

    if (ans != 1e9)
    {
        cout << ans;
    }
    else
    {
        cout << -1;
    }
}
