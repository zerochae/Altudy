#include <bits/stdc++.h>
using namespace std;

// solution 1

// int n;
// int arr1[20005];
// int arr2[20005];
// int main(void)
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     cin >> n;

//     while (n--)
//     {
//         int k, m;
//         cin >> k >> m;
//         for (int i = 0; i < k; i++)
//         {
//             cin >> arr1[i];
//         }
//         for (int i = 0; i < m; i++)
//         {
//             cin >> arr2[i];
//         }
//         // cout << k << " " << m << "\n";
//         // sort(arr1, arr1 + k);
//         // sort(arr2, arr2 + m);
//         int cnt = 0;
//         for (int i = 0; i < k; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 if (arr1[i] > arr2[j])
//                     cnt++;
//             }
//         }
//         cout << cnt << "\n";
//     }
// }

// solution 2

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> v(n + m);

        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            v[i] = {a, 0};
        }
        for (int i = n; i < n + m; i++)
        {
            int b;
            cin >> b;
            v[i] = {b, 1};
        }
        sort(v.begin(), v.end());

        int ans = 0;
        int cnt = 0; // 현재까지 b의 개수
        for (int i = 0; i < n + m; i++)
        {
            if (v[i].second == 0) // 현재 보는 수가 A에 속한 수
            {
                ans += cnt;
            }
            else //현재 보는 수가 B에 속한 수
            {
                cnt++;
            }
        }
        cout << ans << "\n";
    }
}