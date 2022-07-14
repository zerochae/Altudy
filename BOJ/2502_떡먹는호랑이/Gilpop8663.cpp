#include <bits/stdc++.h>
using namespace std;

int d, k;

int A[35];
int B[35];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> d >> k;

    A[1] = 1, B[1] = 0;
    A[2] = 0, B[2] = 1;
    for (int i = 3; i <= d; i++)
    {
        A[i] = A[i - 1] + A[i - 2];
        B[i] = B[i - 1] + B[i - 2];
    }

    // cout << A[d] << " " << B[d] << "\n";

    for (int i = 1; i <= k; i++)
    {
        int num = k - A[d] * i;

        if (num % B[d] == 0)
        {
            cout << i << "\n";
            cout << num / B[d] << "\n";
            return 0;
        }
    }
}

// 10 26 36 62 98 160 258

// 31 +