#include <bits/stdc++.h>
using namespace std;

int n, m;

bool ch[25];
int arr[25][25];

int ans = 99999;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int t = 1; t < n - 1; t++)
    {

        vector<int> v;

        for (int i = 0; i < t; i++)
        {
            v.push_back(0);
        }

        for (int i = 0; i < n - t; i++)
        {
            v.push_back(1);
        }

        do
        {

            int a_sum = 0, b_sum = 0;
            vector<int> a, b;

            for (int i = 0; i < n; i++)
            {
                if (v[i] == 0)
                {
                    a.push_back(i);
                }
                else
                {
                    b.push_back(i);
                }
            }

            for (int i = 0; i < a.size() - 1; i++)
            {
                for (int j = i + 1; j < a.size(); j++)
                {
                    a_sum += arr[a[i]][a[j]] + arr[a[j]][a[i]];
                }
            }

            for (int i = 0; i < b.size() - 1; i++)
            {
                for (int j = i + 1; j < b.size(); j++)
                {
                    b_sum += arr[b[i]][b[j]] + arr[b[j]][b[i]];
                }
            }

            ans = min(ans, abs(a_sum - b_sum));

        } while (next_permutation(v.begin(), v.end()));
    }
    cout << ans;
}
