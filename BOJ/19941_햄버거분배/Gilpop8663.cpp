#include <bits/stdc++.h>
using namespace std;

int n, k;

bool arr[20005];

bool ch[20005];

string str;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    cin >> str;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == 'H')
        {
            arr[i] = 1;
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (str[i] == 'P')
        {
            int st = i - k;
            int en = i + k;

            if (st < 0)
            {
                st = 0;
            }
            if (en >= n)
            {
                en = n;
            }

            // cout << st << " " << en << "\n";
            bool isEat = 0;

            for (int j = st; j <= i; j++)
            {
                if (arr[j] == 1)
                {
                    arr[j] = 0;
                    ans++;
                    isEat = 1;
                    break;
                }
            }
            if (isEat == 0)
            {

                for (int j = i; j <= en; j++)
                {
                    if (arr[j] == 1)
                    {
                        arr[j] = 0;
                        ans++;
                        isEat = 1;
                        break;
                    }
                }
            }
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    cout << ans;
}
