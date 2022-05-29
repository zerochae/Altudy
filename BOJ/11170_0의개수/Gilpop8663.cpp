#include <bits/stdc++.h>
using namespace std;

int t;

int arr[100005];

int d[30005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, m;
        cin >> n >> m;

        int cnt = 0;
        for (int i = n; i <= m; i++)
        {
            string str = to_string(i);
            for (int j = 0; j < str.size(); j++)
            {
                if (str[j] == '0')
                {
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
    }
}