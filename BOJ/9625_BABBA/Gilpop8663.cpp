#include <bits/stdc++.h>
using namespace std;

int n;

pair<int, int> d[50];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    d[1] = {0, 1};
    for (int i = 2; i <= n; i++)
    {
        int a = d[i - 1].second;
        int b = d[i - 1].first + d[i - 1].second;
        d[i] = {a, b};
    }
    cout << d[n].first << " " << d[n].second;
    // d[1] = 0 1
    // d[2] = 1 1
    // d[3] = 1 2
    // d[4] = 2 3
    // d[5] = 3 5
    // B d[1] =1
    // BA d[2] =1
    // BAB d[3] =2
    // BABBA d[4]= 3
    // BABBABAB
}
