#include <bits/stdc++.h>
using namespace std;

int n;

int arr[22];

long long f[21]; // 1~20! 변수

bool ch[22] = {0};

vector<int> numbers;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    f[0] = 1;

    for (int i = 1; i <= 20; i++)
    {
        f[i] = f[i - 1] * i;
    }

    for (int i = 1; i <= n; i++)
    {
        numbers.push_back(i);
    }

    int kind;
    cin >> kind;
    int cnt = 0;
    if (kind == 2)
    {

        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < arr[i]; j++)
            {
                if (ch[j] == 1)
                    continue;
                ans += f[n - i - 1];
            }
            ch[arr[i]] = 1;
        }

        cout << ans + 1;
    }
    else
    {

        long long k;
        cin >> k;

        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (ch[j] == 1)
                    continue;
                if (f[n - 1 - i] < k)
                {
                    k -= f[n - 1 - i];
                }
                else
                {
                    arr[i] = j;
                    ch[j] = 1;
                    break;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    }
}
