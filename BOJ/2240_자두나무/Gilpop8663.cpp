#include <bits/stdc++.h>
using namespace std;

int tree[1005][32][3]; //  i : 현재 몇초 인지  ,  j : 몇번 움직였는지 , k :  현재 어디에 있는 지 .

int arr[1005]; // 각 초마다의 정보를 담는 변수

int w, t;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t >> w;

    for (int i = 1; i <= t; i++)
    {
        int num;
        cin >> num;
        arr[i] = num;
    }

    // d[0][1] = 0;
    // d[1][1] = 1;

    for (int i = 1; i <= t; i++)
    {
        //이동하지 않는 경우 (2번 나무는 이동안하면 못감)
        tree[i][0][1] = tree[i - 1][0][1] + (arr[i] == 1 ? 1 : 0);
        for (int j = 1; j <= w; j++) // j번 이동
        {
            if (i < j)
                break;       // 현재의 시간보다 많이 움직일 수 없다.
            if (arr[i] == 1) // 1번 나무인 경우
            {
                tree[i][j][1] = max(tree[i - 1][j - 1][2], tree[i - 1][j][1]) + 1;
                tree[i][j][2] = max(tree[i - 1][j - 1][1], tree[i - 1][j][2]);
            }
            else // 2번 나무의 경우
            {
                tree[i][j][1] = max(tree[i - 1][j][1], tree[i - 1][j - 1][2]);
                tree[i][j][2] = max(tree[i - 1][j - 1][1], tree[i - 1][j][2]) + 1;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= w; i++)
    {
        ans = max({ans, tree[t][i][1], tree[t][i][2]});
    }
    cout << ans;
}
