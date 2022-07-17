#include <bits/stdc++.h>
using namespace std;

int n, d, k, c;

int arr[30005];

bool ch[3005] = {0};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> d >> k >> c;

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    { // 쿠폰의 초밥을 먹지 않는 경우. 근데 똑같은 초밥을 먹을 수도 있음
        int flag = 0;
        int coupon = 1;
        for (int j = i; j < i + k; j++)
        {
            if (ch[arr[j % n]] == 1)
            {
                flag++;
            }
            else
            {
                ch[arr[j % n]] = 1;
            }

            if (arr[j % n] == c)
            {
                coupon = 0;
            }
        }

        ans = max(ans, k - flag + coupon);
        // memset(ch, 0, sizeof(ch)); // 체크 초기화
        fill(ch, ch + 3005, 0);
    }

    cout << ans;
}
