#include <bits/stdc++.h>
using namespace std;

int n, k;

int arr[10005];

bool ch[10005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    for (int i = 0; i < k; i++)

    {
        ch[i] = 1;
    }

    int cnt = 0;

    set<string> s;

    do
    {
        string str;
        for (int i = 0; i < k; i++)
        {
            str += to_string(arr[i]);
            // cout << arr[i] << " ";
        }
        s.insert(str);
        // cout << str;
        // cout << "\n";
        reverse(arr + k, arr + n);
    } while (next_permutation(arr, arr + n));

    cout << s.size();
}