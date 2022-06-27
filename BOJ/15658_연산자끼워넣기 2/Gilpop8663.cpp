#include <bits/stdc++.h>
using namespace std;

int n, a, b;

int maxAns = -1e9, minAns = 1e9;

int arr[12];

int func(int index, int cur, int plus, int minus, int multi, int div)
{
    if (n == index)
    {
        maxAns = max(maxAns, cur);
        minAns = min(minAns, cur);
        return 0;
    }

    if (plus > 0)
    {
        func(index + 1, cur + arr[index], plus - 1, minus, multi, div);
    }

    if (minus > 0)
    {
        func(index + 1, cur - arr[index], plus, minus - 1, multi, div);
    }

    if (multi > 0)
    {
        func(index + 1, cur * arr[index], plus, minus, multi - 1, div);
    }

    if (div > 0)
    {
        func(index + 1, cur / arr[index], plus, minus, multi, div - 1);
    }
    return 0;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int plus, minus, multi, div;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cin >> plus >> minus >> multi >> div;

    func(1, arr[0], plus, minus, multi, div);

    cout << maxAns << "\n";
    cout << minAns;
}
