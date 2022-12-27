#include <bits/stdc++.h>
using namespace std;

int n;

int arr[120];

vector<string> dic[120];

int numCount(int x, int y)
{
    int count = 0;
    vector<string> v1 = dic[x], v2 = dic[y];

    for (int i = 0; i < v1.size(); i++)
    {
        for (int j = 0; j < v2.size(); j++)
        {
            if (v1[i] == v2[j])
                count++;
        }
    }
    return count;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string animal;
        cin >> animal;
        int k;

        cin >> k;
        arr[i] = k;

        for (int j = 0; j < k; j++)
        {
            string peww;
            cin >> peww;
            dic[i].push_back(peww);
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            ans = max(ans, numCount(i, j));
        }
    }

    cout << ans + 1;
}