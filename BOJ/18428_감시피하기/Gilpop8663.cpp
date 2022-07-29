#include <bits/stdc++.h>

using namespace std;

int n;

int arr[8][8];
int tmp[8][8];

vector<pair<int, int>> x_arr;

queue<tuple<int, int, int>> q;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool func()
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (tmp[i][j] == 1)
            {
                for (int k = 0; k < 4; k++)
                {
                    q.push({i, j, k});
                }
            }

            while (!q.empty())
            {
                tuple<int, int, int> cur = q.front();
                q.pop();

                int x = get<0>(cur);
                int y = get<1>(cur);
                int dir = get<2>(cur);

                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                    continue;

                if (tmp[nx][ny] == 1)
                    continue;
                if (tmp[nx][ny] == 3)
                    continue;
                if (tmp[nx][ny] == 0)
                {
                    q.push({nx, ny, dir});
                }
                if (tmp[nx][ny] == 2)
                    return true;
            }
        }
    }
    return false;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char s;
            cin >> s;

            if (s == 'X')
            {
                arr[i][j] = 0;
            }
            else if (s == 'T')
            {
                arr[i][j] = 1;
            }
            else if (s == 'S')
            {
                arr[i][j] = 2;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tmp[i][j] = arr[i][j];

            if (arr[i][j] == 0)
            {
                x_arr.push_back({i, j});
            }
        }
    }

    int len = x_arr.size();
    for (int i = 0; i < len - 2; i++)
    {
        for (int j = i + 1; j < len - 1; j++)
        {
            for (int k = j + 1; k < len; k++)
            {
                int one = x_arr[i].first;
                int two = x_arr[i].second;

                int three = x_arr[j].first;
                int four = x_arr[j].second;

                int five = x_arr[k].first;
                int six = x_arr[k].second;

                tmp[one][two] = 3;
                tmp[three][four] = 3;
                tmp[five][six] = 3;

                if (func() == true)
                {
                    tmp[one][two] = 0;
                    tmp[three][four] = 0;
                    tmp[five][six] = 0;
                    continue;
                }
                else if (func() == false)
                {
                    cout << "YES";
                    return 0;
                }
            }
        }
    }

    cout << "NO";
    return 0;
}
