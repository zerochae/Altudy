#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;

long long arr[1000005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    arr[n] = 1ll << 62 + 1;
    long long mxval = 1;
    int cnt = 1;
    int mxcnt = 0;
    for (int i = 0; i < 62; i++)
    {
        mxval = mxval * 2;
    }
    mxval = -mxval - 1;

    for (int i = 1; i <= n; i++)
    {
        if (arr[i - 1] == arr[i]) // 같다면 cnt 가 증가함
            cnt++;
        else
        {
            if (mxcnt < cnt) // 아니라면 mxcnt가 현재보다 높다면 cnt 를 mxcnt로 함 그리고 mxval을
            {
                mxcnt = cnt;
                mxval = arr[i - 1];
            }
            cnt = 1;
        }
    }
    // if (cnt > mxcnt)
    //     mxval = arr[n - 1];
    cout << mxval;
}