#include <bits/stdc++.h>
using namespace std;

int a, b;
// 2000000000
int n;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b;
    cin >> n;
    int num;
    num = a % b;

    // cout << num << "\n";
    string str;
    bool flag = 0;

    char ans;

    int cnt = 0;

    while (cnt < n)
    {
        num *= 10;

        int tmp = num / b;
        str += to_string(tmp);
        num %= b;
        cnt++;

        // cout << str << " " << cnt << "\n";
    }
    cout << str[n - 1];
}
