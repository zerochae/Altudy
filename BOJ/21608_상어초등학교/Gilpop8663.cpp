#include <bits/stdc++.h>
using namespace std;

int n;

tuple<int, int, int, int> arr[405];

int d[25][25];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool comp(tuple<int, int, int, int> v1, tuple<int, int, int, int> v2)
{

    if (get<0>(v1) == get<0>(v2))
    {

        if (get<1>(v1) == get<1>(v2))
        {
            if (get<2>(v1) == get<2>(v2))
            {

                return get<3>(v1) < get<3>(v2);
            }
            else
            {

                return get<2>(v1) < get<2>(v2);
            }
        }

        else
        {
            return get<1>(v1) > get<1>(v2);
        }
    }
    else
    {
        return get<0>(v1) > get<0>(v2);
    }
}

pair<int, int> first(vector<int> nums)
{

    vector<tuple<int, int, int, int>> maxNum;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int cnt = 0;
            int emptyCnt = 0;

            if (d[i][j] != 0)
                continue;

            for (int k = 0; k < 4; k++)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                    continue;

                if (d[nx][ny] == 0)
                {
                    emptyCnt++;
                    continue;
                }

                for (int l = 0; l < 4; l++)
                {
                    if (d[nx][ny] == nums[l])
                    {
                        cnt++;
                        break;
                    }
                }
            }
            maxNum.push_back({cnt, emptyCnt, i, j});
        }
    }

    sort(maxNum.begin(), maxNum.end(), comp);

    // for (int i = 0; i < maxNum.size(); i++)
    // {
    //     cout << get<0>(maxNum[i]) << " " << get<1>(maxNum[i]) << " " << get<2>(maxNum[i]) << " " << get<3>(maxNum[i]) << "\n";
    // }

    // cout << "\n";

    return {get<2>(maxNum[0]), get<3>(maxNum[0])};
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int ans = 0;

    for (int i = 0; i < n * n; i++)
    {
        int num, one, two, three, four;

        cin >> num >> one >> two >> three >> four;

        arr[num] = {one, two, three, four};

        vector<int> tmp;
        tmp.push_back(one);
        tmp.push_back(two);
        tmp.push_back(three);
        tmp.push_back(four);

        pair<int, int> pos = first(tmp);

        d[pos.first][pos.second] = num;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int num = d[i][j];
            int cnt = 0;
            vector<int> tmp;
            tmp.push_back(get<0>(arr[num]));
            tmp.push_back(get<1>(arr[num]));
            tmp.push_back(get<2>(arr[num]));
            tmp.push_back(get<3>(arr[num]));

            for (int k = 0; k < 4; k++)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                    continue;

                for (int l = 0; l < 4; l++)
                {
                    if (d[nx][ny] == tmp[l])
                    {
                        cnt++;
                        break;
                    }
                }
            }

            if (cnt == 1)
            {
                ans += 1;
            }
            else if (cnt == 2)
            {
                ans += 10;
            }
            else if (cnt == 3)
            {
                ans += 100;
            }
            else if (cnt == 4)
            {
                ans += 1000;
            }
        }
    }

    cout << ans;
}
