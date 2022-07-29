#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, k;

pair<int, int> s[105];

int d[105][100005]; // F[A][B] = C : A번째 물건까지 왔고, 가방의 무게가 B일 때 가방에 담긴 물건들의 가치는 C입니다.

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> s[i].first >> s[i].second;
    }

    for (int i = 1; i <= n; i++)
    {
        int w = s[i].first;
        int v = s[i].second;
        for (int j = 1; j <= k; j++)
        {
            if (j >= w)
            {
                d[i][j] = max(d[i - 1][j], d[i - 1][j - w] + v);
            }
            else
            {
                d[i][j] = d[i - 1][j];
            }
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= k; j++)
    //     {

    //         cout << d[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    cout << d[n][k];
}
