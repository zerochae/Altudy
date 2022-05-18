#include <bits/stdc++.h>
using namespace std;

int n;

int d[12];
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    d[1] = 1;
    d[2] = 2; // 1+1 , 2
    d[3] = 4; // 1+1+1 , 1+2  , 2+1, 3
    d[4] = 7; // 1+1+1+1, 1+1+2, 1+2+1, 2+1+1, 2+2,1+3 , 3+1
              // d[i] = d[i-1] +1  ,

    // 1+1+1+1 ,  2+1+1 , 1+2+1, 3+1,
    // 2+2 , 1+1+2
    // 1+3
    for (int i = 4; i <= 10; i++)
    {
        d[i] = d[i - 3] + d[i - 2] + d[i - 1];
    }
    while (n--)
    {
        int t;
        cin >> t;
        cout << d[t] << "\n";
    }
}