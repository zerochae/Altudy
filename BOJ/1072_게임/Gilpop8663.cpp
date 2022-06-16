#include <bits/stdc++.h>
using namespace std;

long long x, y;

const int MAX = 1000000000;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> x >> y;

    int z = (y * 100) / x;

    if (z >= 99)
    {
        cout << -1 << "\n";
        return 0;
    }

    int low = 0, high = MAX;

    int result = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int tmpZ = (100 * (y + mid)) / (x + mid);

        // cout << mid << " " << tmpZ << "\n";
        if (z >= tmpZ)
        {
            result = mid + 1;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << result << "\n";

    // cout << z;
}
