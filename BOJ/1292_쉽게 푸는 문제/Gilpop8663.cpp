#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int A, B;

int num[1205];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> B;
    int count = 1;

    for (int i = 1; i <= 1000; i++)
    {
        if (count >= 1001)
            break;

        int cnt = 0;
        while (true)
        {
            if (cnt >= i)
                break;
            num[count++] = i;
            cnt++;
        }
    }

    int sum = 0;
    for (int i = A; i <= B; i++)
    {
        sum += num[i];
    }

    cout << sum;
}
