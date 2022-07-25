#include <bits/stdc++.h>
using namespace std;

string n;

char arr[11];

bool func()
{
    for (int i = 0; i < n.size(); i++)
    {
        if (arr[i] == arr[i + 1])
            return false;
    }
    return true;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int ans = 0;
    for (int i = 0; i < n.size(); i++)
    {
        arr[i] = n[i];
    }

    sort(arr, arr + n.size());

    do
    {
        if (func())
            ans++;
    } while (next_permutation(arr, arr + n.size()));

    cout << ans;
}
