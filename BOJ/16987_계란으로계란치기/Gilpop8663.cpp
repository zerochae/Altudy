#include <bits/stdc++.h>
using namespace std;

int n;
int s[10];
int w[10];
int mx = 0;
int cnt = 0; // 깨져있는 계란의 수

void solve(int k) // a번째 계란으로 다른 걸 깰 차례
{
    if (k == n)
    {
        // for (int i = 0; i < n; i++)
        // {
        //     // cout << s[i] << " " << w[i];
        // }
        // cout << "\n";
        mx = max(mx, cnt); //계란을 깨트린 횟수
        return;
    }
    if (s[k] <= 0 || cnt == n - 1) // k번째 계란이 깨져있거나 다른 모든 계란이 깨져있다면 넘어감
    {
        solve(k + 1);
        return;
    }

    for (int i = 0; i < n; i++) // i번째 계란을 k번째로 내려치려고 함
    {
        if (k == i || s[i] <= 0) // k번쨰와 i번째 계란이 같은 순서면 넘어감 , i번째 계란이 꺠졌다면 넘어감
            continue;
        s[k] -= w[i];  // k번쨰 무게로 i번째 내구도를 깍음
        s[i] -= w[k];  // i번째 무게로  k번째 내구도를 깍음
        if (s[k] <= 0) // k번째 계란이 꺠졌다면 cnt ++
            cnt++;
        if (s[i] <= 0) // i번째 계란이 깨졌다면 cnt ++
            cnt++;
        solve(k + 1);  // 다른 계란을 내려치기
        if (s[k] <= 0) // 결과값을 확인했으니 백트래킹
            cnt--;
        if (s[i] <= 0)
            cnt--;
        s[k] += w[i]; //복구중..
        s[i] += w[k];
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> s[i] >> w[i]; // 내구도와 무게
        // cout << s[i] << w[i] << "\n";
    }
    solve(0);
    cout << mx; // 최대값 출력
}
