#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[105];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int gender, num;
        cin >> gender >> num;

        if (gender == 1)
        {
            // cout << gender << " " << num << "\n";

            for (int j = num; j <= n; j += num)
            {
                if (arr[j] == 1)
                {
                    arr[j] = 0;
                }
                else
                {
                    arr[j] = 1;
                }
            }
            // for (int j = 1; j <= n; j++)
            // {
            //     cout << arr[j] << " ";
            // }
            // cout << "\n";
        }
        else
        {
            int cnt = 0;
            int number = min(n - num, num - 1);
            // cout << gender << " " << num << " " << number << "\n";

            // for (int j = 1; j <= n; j++)
            // {
            //     cout << arr[j] << " ";
            // }
            // cout << "\n";
            for (int j = 1; j <= number; j++)
            {
                // cout << arr[num - j] << " " << arr[num + j] << "\n";
                if (arr[num - j] == arr[num + j])
                {
                    cnt++;
                }
                else
                {
                    break;
                }
            }

            if (arr[num] == 1)
            {
                arr[num] = 0;
            }
            else
            {
                arr[num] = 1;
            }

            for (int j = 1; j <= cnt; j++)
            {
                if (arr[num - j] == 1)
                {
                    arr[num - j] = 0;
                    arr[num + j] = 0;
                }
                else
                {
                    arr[num - j] = 1;
                    arr[num + j] = 1;
                }

                // cout << "cnt는: " << cnt << " "
                //      << "number는 : " << number << "\n";
            }
            // for (int j = 1; j <= n; j++)
            // {
            //     cout << arr[j] << " ";
            // }
            // cout << "\n";
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";

        if (i % 20 == 0)
        {
            cout << "\n";
        }
    }
}
