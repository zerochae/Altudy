#include <bits/stdc++.h>
using namespace std;

int n, m;

vector<pair<int, int>> arr[100005];

int d[105][105];

const int INF = 0x3f3f3f3f;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    fill(&d[0][0], &d[104][105], INF);

    for (int i = 0; i < m; i++)
    {
        int st, en, cost;
        cin >> st >> en >> cost;

        d[st][en] = min(d[st][en], cost);
    }

    for (int i = 1; i <= n; i++)
        d[i][i] = 0;

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {

                // cout << i << " " << j << " " << k << "\n";
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    // cout << "\n";

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (d[i][j] == INF)
            {
                cout << "0"
                     << " ";
            }
            else
            {
                cout << d[i][j] << " ";
            }
        }
        cout << "\n";
    }
}
