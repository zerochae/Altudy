#include <bits/stdc++.h>
using namespace std;

set<int> s;

int n;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        s.insert(num);
    }

    int arr[s.size()];

    int cnt = 0;
    for (auto i = s.begin(); i != s.end(); ++i)
    {
        arr[cnt++] = *i;
    }

    sort(arr, arr + s.size());

    for (int i = 0; i < s.size(); i++)
    {
        cout << arr[i] << " ";
    }
}
