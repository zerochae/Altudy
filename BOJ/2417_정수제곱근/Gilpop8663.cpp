#include <bits/stdc++.h>
using namespace std;

long long n;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    long long low = 0;
    long long high = sqrt(n);
    long long mid;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (mid >= sqrt(n))
        {
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    if (mid * mid >= n)
    {
        cout << mid;
    }
    else
    {
        cout << mid + 1;
    }
    // cout << sqrt(n) << " " << mid << " " << mid * mid << "\n";
}
