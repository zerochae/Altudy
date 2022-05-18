#include <bits/stdc++.h>

using namespace std;

string str;

string arr[1005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;
    for (int i = 0; i < str.size(); i++)
    {
        arr[i] = str.substr(i);
        // cout << arr[i] << "\n";
    }

    sort(arr, arr + str.size());

    for (int i = 0; i < str.size(); i++)
    {
        cout << arr[i] << "\n";
    }
}