#include <bits/stdc++.h>
using namespace std;

int n;
int d[1005][3];
int R[1005];
int G[1005];
int B[1005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> R[i] >> G[i] >> B[i]; // 빨강 , 초록 , 파랑
    }

    d[1][0] = R[1];
    d[1][1] = G[1];
    d[1][2] = B[1];

    for (int i = 2; i <= n; i++)
    {
        d[i][0] = min(d[i - 1][1], d[i - 1][2]) + R[i]; //전번째 파랑 초록집을 비교함

        d[i][1] = min(d[i - 1][0], d[i - 1][2]) + G[i];

        d[i][2] = min(d[i - 1][0], d[i - 1][1]) + B[i];
        // cout << i << " " << d[i][0] << " " << d[i][1] << " " << d[i][2] << "\n";
    }

    // cout << d[n][0] << " " << d[n][1] << " " << d[n][2] << "\n";
    cout << min(d[n][0], min(d[n][1], d[n][2]));
    //빨강 집일때   d[i][0] = min(d[i-1][1],d[i-1][2]) + s[i][0];
}