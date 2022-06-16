#include <bits/stdc++.h>
using namespace std;

int n;

double arr[10005];
double d[10005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    double ans = 0;
    double sum = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    d[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        d[i] = max(d[i - 1] * arr[i], arr[i]);
        // cout << d[i] << " ";
    }
    cout << fixed;
    cout.precision(3);
    cout << *max_element(d, d + n);
}