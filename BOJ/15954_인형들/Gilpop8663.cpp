#include <bits/stdc++.h>
using namespace std;

double t, n, k;

double arr[505];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    int tempK = k;

    int idx = 0;

    double minSd = 1e9;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    while (tempK <= n)
    {

        double sum = 0;
        double var = 0;
        double sd = 0;

        if (idx + tempK - 1 <= n - 1)
        {

            for (int i = idx; i < idx + tempK; i++)
            {
                sum += arr[i];
            }

            double m = sum / (double)tempK;

            for (int i = idx; i < idx + tempK; i++)
            {
                var += (arr[i] - m) * (arr[i] - m);
            }

            var /= double(tempK);

            sd = sqrt(var);

            if (minSd > sd)
            {
                minSd = sd;
            }

            idx += 1;
        }
        else
        {
            idx = 0;
            tempK++;
        }
    }

    cout.fixed;
    cout.precision(11);
    cout
        << minSd;
}
