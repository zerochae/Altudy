#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[11][11];

bool ch[11];

queue<int> q;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    vector<int> tmp;
    for (int i = 0; i < n; i++)
    {
        tmp.push_back(i);
    }

    int ans = 10000000;
    do
    {
        bool isNot = 0;

        int first = tmp[0];
        int sum = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int num = tmp[i];
            int num2 = tmp[i + 1];
            // cout << tmp[i] << " ";
            sum += arr[num][num2];
            if (arr[num][num2] == 0)
            {
                isNot = 1;
            }
            // cout << arr[num][num2] << " ";
        }
        if (arr[tmp[n - 1]][first] == 0)
        {
            isNot = 1;
        }

        if (isNot == 1)
            continue;
        sum += arr[tmp[n - 1]][first];
        // cout << arr[tmp[n - 1]][first];
        // cout << sum << "\n";
        ans = min(ans, sum);

    } while (next_permutation(tmp.begin(), tmp.end()));

    cout << ans;
    // n! /(#pragma endregion (n-r) ! * r!);
}
