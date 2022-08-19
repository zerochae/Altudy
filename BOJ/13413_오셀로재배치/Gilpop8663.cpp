#include <bits/stdc++.h>
using namespace std;

int t, n;

int arr[1005];
int arr2[1005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;

    while (t--)
    {
        cin >> n;
        string str1, str2;
        cin >> str1 >> str2;

        int wCnt = 0;
        int bCnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (str1[i] != str2[i])
            {

                if (str1[i] == 'W')
                {
                    wCnt++;
                }
                else
                {
                    bCnt++;
                }
            }
        }
        int ans = 0;

        while (wCnt != 0 && bCnt != 0)
        {
            ans++;
            wCnt--;
            bCnt--;
        }
        ans += wCnt + bCnt;

        cout << ans << "\n";
        // cout << wCnt << " " << bCnt << "\n";
    }
}
