#include <bits/stdc++.h>
using namespace std;

int l, n, m;

int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dl[6] = {0, 0, 0, 0, 1, -1};

int arr[32][32][32];

bool ch[32][32][32] = {0};

queue<tuple<int, int, int, int>>
    q;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> l >> n >> m)
    {
        fill(&arr[0][0][0], &arr[31][31][32], 0);
        fill(&ch[0][0][0], &ch[31][31][32], 0);

        if (l == 0 && n == 0 && m == 0)
            break;

        for (int i = 0; i < l; i++)
        {
            for (int j = 0; j < n; j++)
            {
                string str;
                cin >> str;
                for (int k = 0; k < m; k++)
                {
                    if (str[k] == 'S')
                    {
                        arr[i][j][k] = 3;
                    }
                    else if (str[k] == 'E')
                    {
                        arr[i][j][k] = 4;
                    }
                    else if (str[k] == '.')
                    {
                        arr[i][j][k] = 2;
                    }
                }
            }
        }

        for (int i = 0; i < l; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < m; k++)
                {
                    if (arr[i][j][k] == 3)
                    {
                        bool isFind = 0;
                        int ansCnt = 0;

                        q.push({i, j, k, 0});
                        ch[i][j][k] = 1;

                        while (!q.empty())
                        {
                            auto cur = q.front();
                            q.pop();

                            int L = get<0>(cur);
                            int R = get<1>(cur);
                            int C = get<2>(cur);
                            int cnt = get<3>(cur);

                            if (arr[L][R][C] == 4)
                            {
                                isFind = 1;
                                ansCnt = cnt;
                            }

                            for (int w = 0; w < 6; w++)
                            {
                                int nl = L + dl[w];
                                int nx = R + dx[w];
                                int ny = C + dy[w];

                                if (nx < 0 || ny < 0 || nl < 0 || nx >= n || ny >= m || nl >= l || arr[nl][nx][ny] == 0)
                                    continue;
                                if (ch[nl][nx][ny] == 1)
                                    continue;

                                q.push({nl, nx, ny, cnt + 1});
                                ch[nl][nx][ny] = 1;
                            }
                        }
                        if (isFind == 0)
                        {
                            cout << "Trapped!"
                                 << "\n";
                        }
                        else
                        {
                            cout << "Escaped in " << ansCnt << " minute(s)."
                                 << "\n";
                        }
                    }
                }
            }
        }
    }
}
