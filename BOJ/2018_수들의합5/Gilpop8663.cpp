#include <bits/stdc++.h>
using namespace std;

int n;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int cnt = 0;

    for (int i = 1; i <= n; i++)
    {

        int num = 0;
        int plus = i;
        while (true)
        {
            if (num > n)
            {
                break;
            }
            if (num == n)
            {
                cnt++;
                break;
            }
            num += plus++;
        }
    }
    cout << cnt;
}
