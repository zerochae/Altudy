#include <bits/stdc++.h>
using namespace std;

int n;

int arr[100005];

bool ch[100005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    long long sum = 0;
    long long powSum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
        powSum += arr[i] * arr[i];
    }

    sum *= sum;

    sum -= powSum;

    sum /= 2;

    cout
        << sum;
}

// 4 9 16

// 81 13 29

// 52  /2 =26;
