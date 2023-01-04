#include <bits/stdc++.h>
using namespace std;

long long n, m;

const int MAX = 10000005;

bool arr[MAX];
vector<int> Prime;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    arr[0] = 1;
    arr[1] = 1;

    for (int i = 2; i < MAX; i++)
    {
        if (arr[i] == 1)
            continue;
        Prime.push_back(i);

        for (int j = i * 2; j < MAX; j += i)
        {
            arr[j] = 1;
        }
    }

    int count = 0;

    for (auto it : Prime)
    {
        long long curr = 1LL * it; // 현재 숫자
        long long tmp = curr;
        while (tmp <= m / curr) // tmp * curr <= B 일 때만
        {
            tmp *= curr;  // 제곱
            if (tmp >= n) // 범위 내이면 count +=1;
            {
                count += 1;
            }
        }
    }

    cout << count;

    // 10_0000_0000_0000
}
