#include <bits/stdc++.h>
using namespace std;

int n;

int d[100005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    // d[1] = 1;
    // 1 , 1+1 , 1+1+1 , 2**2 , 2**2 +1 , 2***2+1+1 , 2**2+1+1+1;
    // 142의 경우 13*13 + 3  =4 이 아닌 5**2 + 6**2 + 9**2 =3 임
    // 9 = d[9-1]+1 , d[9-4] +1 , d[9-9] +1 ;

    for (int i = 1; i <= n; i++)
    {
        d[i] = i;
        for (int j = 1; j * j <= i; j++)
        {
            d[i] = min(d[i], d[i - j * j] + 1);
            // cout << i << " " << d[i] << " " << d[i - j * j] << "\n";
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << d[i] << "\n";
    // }

    cout << d[n];
}
