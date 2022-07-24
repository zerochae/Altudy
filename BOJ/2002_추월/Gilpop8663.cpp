#include <bits/stdc++.h>
using namespace std;

int n, m;

string arr[1005];
string arr2[1005];

map<string, bool> s;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        s.insert({arr[i], 0});
    }
    for (int i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }

    int ans = 0;
    int idx = 0, idx2 = 0;
    while (1)
    {
        if (idx == n - 1 || idx2 == n - 1)
        {
            break;
        }

        if (s.find(arr[idx])->second == 1)
        {
            idx++;
            continue;
        }

        if (arr[idx] == arr2[idx2])
        {
            idx++;
            idx2++;
        }
        else
        {
            s.find(arr2[idx2])->second = 1;
            ans++;
            idx2++;
        }
    }

    cout << ans;
}
