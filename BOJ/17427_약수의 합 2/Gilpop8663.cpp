#include <bits/stdc++.h>
using namespace std;

int n;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    long long ans = 0;

    // 10을 예로 들면 10에는
    // 1이 10 개 , 2는 5개 , 3은 3개 4는 2개 5는 2개 6.7.8.9,10 은 1개임

    for (int i = 1; i <= n; i++)
    {
        ans += (n / i) * i;
    }

    cout << ans << "\n";
}
