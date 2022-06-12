#include <bits/stdc++.h>
using namespace std;

int n;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    vector<int> arr;

    for (int i = 1; i <= n; i++)
    {
        arr.push_back(i);
    }

    do
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    } while (next_permutation(arr.begin(), arr.end()));
}
