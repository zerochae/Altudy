#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int phone[10000], Y, M;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int sum;
    for (int i = 0; i < n; i++)
    {
        cin >> phone[i];
    }

    for (int i = 0; i < n; i++)
    {

        Y += ((phone[i] / 30) + 1) * 10;
        // cout << Y;
    }

    for (int i = 0; i < n; i++)
        M += ((phone[i] / 60) + 1) * 15;

    if (Y < M)
        cout << "Y " << Y;
    else if (Y > M)
        cout << "M " << M;
    else
        cout << "Y M " << Y;
}
