#include <bits/stdc++.h>
using namespace std;

int n;

int price;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> price;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int num, cnt;
        cin >> num >> cnt;
        ans += num * cnt;
    }

    if (ans == price)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}
