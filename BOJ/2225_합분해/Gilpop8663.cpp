#include <bits/stdc++.h>
using namespace std;

int N, K;

int MOD = 1000000000;

long long d[205][205] = {0}; //   DP[a][b] = c 의 의미는 "a개 더해서 그 합이 b가 되는 경우의 수는 c개 입니다." 이다.

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;

    for (int i = 0; i <= N; i++)
    {
        d[1][i] = 1; // 한개만 더해서 i가 나오는 수는 1개이다
    }

    for (int k = 2; k <= K; k++)
    {
        for (int n = 0; n <= N; n++)
        {
            for (int i = 0; i <= n; i++)
            {
                d[k][n] = d[k][n] + d[k - 1][i];
            }
            d[k][n] = d[k][n] % MOD;
        }
    }

    cout << d[K][N];
}
