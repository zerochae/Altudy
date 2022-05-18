#include <bits/stdc++.h>

using namespace std;

int n;

pair<int, int> a[20];

int d[20]; // i번째 일에 상담을 시작했을 때 얻을 수 있는 최대 수익

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first >> a[i].second;
        // cout << a[i].first << " " << a[i].second;
    }
    int ans = 0;
    for (int i = n; i > 0; i--)
    {
        // i 번째 일을 할 수 있는 경우
        if (i + a[i].first <= n + 1)
        {
            // i번째 일에 상담을 했을 때와 상담을 하지 않았을 때 얻을 수 있는 수익 중 최대 수익을 취함
            d[i] = max(d[i + a[i].first] + a[i].second, d[i + 1]);
        }
        else
        {
            d[i] = d[i + 1];
        }
    }

    cout << *max_element(d, d + n + 5);
}