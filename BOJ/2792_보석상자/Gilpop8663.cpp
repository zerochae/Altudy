#include <bits/stdc++.h>
using namespace std;

long long n, m;

long long arr[300005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    long long ans = 1e9;

    long long low = 1;
    long long high = 1e9;
    for (long long i = 0; i < m; i++)
    {
        cin >> arr[i];
    }

    while (low <= high)
    {
        long long cnt = 0;
        long long mid = (low + high) / 2;

        for (long long i = 0; i < m; i++)
        {
            cnt += arr[i] / mid; // 보석을 인원수(mid)로 나눔;
            if (arr[i] % mid != 0)
            { // mid로 나누었는데 0이 아니라면 1개 이상의 보석이 남은 것이므로 인원수 추가해줌
                cnt++;
            }
        }

        if (cnt <= n)
        { //나눈 학생수가 학생보다 작다면
            high = mid - 1;
            if (mid <= ans)
            {
                ans = mid;
            }
        }
        else
        {
            low = mid + 1;
        }
    }

    cout << ans << "\n";
}
