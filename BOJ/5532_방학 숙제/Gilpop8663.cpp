#include <bits/stdc++.h>
using namespace std;

int L, B, A, C, D;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> L >> A >> B >> C >> D;

    int day = L;

    int mathDay = B % D == 0 ? B / D : B / D + 1;
    int koreanDay = A % C == 0 ? A / C : A / C + 1;

    int ans = day - max(mathDay, koreanDay);

    cout << ans;
}
