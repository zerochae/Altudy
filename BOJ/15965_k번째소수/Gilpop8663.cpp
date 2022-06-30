#include <bits/stdc++.h>
using namespace std;

int n;

int m = 7500000;

bool arr[7500005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> prime;

    arr[0] = 1;
    arr[1] = 1;

    for (int i = 2; i <= m; i++)
    {
        if (arr[i] == 1)
            continue;
        prime.push_back(i);
        for (int j = i * 2; j <= m; j += i)
        {
            arr[j] = 1;
        }
    }

    // cout << prime.size();

    cin >> n;

    cout << prime[n - 1];
}
