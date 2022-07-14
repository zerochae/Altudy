#include <bits/stdc++.h>
using namespace std;

int t, n;

long long d[65][10] = {0};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    // 1의 자리 =  0 1 2 3 4 5 6 7 8 9 = 9;

    // 2의 자리 00~09 = 10 + 11~19 = 9... 55;

    // 3의 자리  000~099 = 100 , 111~ 199

    for (int i = 0; i <= 9; i++)
    {
        d[1][i] = 1;
        // cout << d[1][i] << " ";
    }

    for (int i = 2; i <= 64; i++)
    {
        for (int j = 0; j <= 9; j++)
        {

            for (int k = j; k <= 9; k++)
            {
                d[i][j] += d[i - 1][k];
            }
        }
    }
    while (t--)
    {
        cin >> n;

        long long result = 0;

        for (int i = 0; i <= 9; i++)
        {
            result += d[n][i];
        }

        cout << result << "\n";
    }
}
