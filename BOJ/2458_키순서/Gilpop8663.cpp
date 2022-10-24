#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[505][505];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

const int INF = 1e9;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    fill(&arr[0][0], &arr[504][505], INF);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        arr[a][b] = 1;
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

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= n; j++)
        {
            if (arr[i][j] != INF)
            {
                cnt++;
            }
            else if (arr[j][i] != INF)
            {
                cnt++;
            }
        }
        if (cnt == n - 1)
        {
            ans++;
        }
    }

    cout << ans;
}
