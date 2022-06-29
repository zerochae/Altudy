#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[1005][1005];

int ch[1005][1005];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<pair<int, int>> q;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    // cout << n << " " << m << "\n";
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        string numbers;
        getline(cin, numbers);
        for (int j = 0; j < m; j++)
        {
            // cout << numbers[j] << " ";

            // arr[i][j] = str[i][j] - '0';
            if (numbers[j] == '1')
            {
                arr[i][j] = 1;
            }
            else
            {
                arr[i][j] = 0;
            }
        }
        // cout << "\n";
    }

    for (int i = 0; i < m; i++)
    {
        if (ch[0][i] == 1)
            continue;

        // cout << arr[0][i] << " ";
        if (arr[0][i] == 0)
        {
            ch[0][i] = 1;
            q.push({0, i});
        }

        while (!q.empty())
        {
            pair<int, int> cur = q.front();
            q.pop();

            int x = cur.first;
            int y = cur.second;

            for (int k = 0; k < 4; k++)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || ny < 0 || nx >= n || ny >= m || ch[nx][ny] == 1)
                    continue;

                if (arr[nx][ny] == 0)
                {
                    q.push({nx, ny});

                    ch[nx][ny] = 1;
                }
            }

            // cout << x << " " << y << "\n";
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (ch[n - 1][i] == 1)
        {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
}
