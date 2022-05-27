#include <bits/stdc++.h>
using namespace std;

int board[502][502];
bool vis[502][502];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n, m;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int, int>> Q;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char str;
            cin >> str;
            if (str == 'c')
            {
                board[i][j] = 1;
            }
            else
            {
                board[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 1)
            {
                cout << "0"
                     << " ";
                continue;
            }

            int num = j - 1;
            int cnt = 0;
            while (true)
            {
                cnt++;
                if (board[i][num--] == 1)
                {
                    cout << cnt << " ";
                    break;
                }

                if (cnt > j)
                {
                    cout << -1 << " ";
                    break;
                }
            }
        }
        cout << "\n";
    }
}
