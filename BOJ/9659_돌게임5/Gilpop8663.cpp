#include <bits/stdc++.h>
using namespace std;

long long n;

int d[1005]; // 돌이 i개 있을 때 선공이 이기면 0, 후공이 이기면 1
string ans[] = {"SK", "CY"};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    if (n % 2 == 1)
    {
        cout << ans[0];
    }
    else
    {
        cout << ans[1];
    }
}
