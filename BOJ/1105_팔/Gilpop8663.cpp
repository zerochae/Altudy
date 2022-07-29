#include <bits/stdc++.h>
using namespace std;

int L, R;

int d[15];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> L >> R;

    int ans = 999;

    string A = to_string(L);
    string B = to_string(R);

    if (A.length() != B.length())
    {
        cout << 0;
        return 0;
    }

    int cnt = 0;
    for (int i = 0; i < A.length(); i++)
    {
        if (A[i] == '8' & B[i] == '8')
        {
            cnt++;
        }
        else if (A[i] != B[i])
        {
            break;
        }
    }

    cout << cnt;
}
