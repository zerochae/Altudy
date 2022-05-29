#include <bits/stdc++.h>
using namespace std;

int t;
int n;

int arr[10];
int arr2[10];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 9; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < 9; i++)
    {
        cin >> arr2[i];
    }
    int sum1 = 0;
    int sum2 = 0;

    for (int i = 0; i < 9; i++)
    {
        sum1 += arr[i];
        if (sum1 > sum2)
        {
            cout << "Yes";
            return 0;
            break;
        }
        sum2 += arr2[i];
    }
    cout << "No";
}
