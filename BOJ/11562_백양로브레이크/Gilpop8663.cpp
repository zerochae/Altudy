#include <bits/stdc++.h>
using namespace std;

int n, m, que;

int arr[255][255];

const int INF = 0x3f3f3f3f;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    fill(&arr[0][0], &arr[254][255], INF);

    for (int i = 1; i <= n; i++)
        arr[i][i] = 0;

    for (int i = 0; i < m; i++)
    {
        int u, v, b;
        cin >> u >> v >> b;
        arr[u][v] = 0;
        if (b == 1)
        {
            arr[v][u] = 0;
        }
        else
        {
            arr[v][u] = 1;
        }
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }

    cin >> que;

    for (int i = 0; i < que; i++)
    {
        int st, en;
        cin >> st >> en;

        cout << arr[st][en] << "\n";
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
}
