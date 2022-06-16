#include <bits/stdc++.h>
using namespace std;

int n;

string arr1[500005];

int m;
int arr2[500005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    sort(arr1, arr1 + n);

    vector<string> s;
    for (int i = 0; i < m; i++)
    {
        string str;

        cin >> str;
        if (binary_search(arr1, arr1 + n, str) == 1)
        {
            s.push_back(str);
        }
    }

    cout << s.size() << "\n";

    sort(s.begin(), s.end());

    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i] << "\n";
    }
}
