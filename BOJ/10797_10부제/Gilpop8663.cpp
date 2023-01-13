#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int day;
    cin >> day;

    int ans = 0;
    for (int i = 0; i < 5; i++)
    {
        int num;
        cin >> num;
        if (day == num)
        {
            ans++;
        }
    }
    cout << ans;
}
