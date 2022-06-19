#include <bits/stdc++.h>
using namespace std;

int n;

int arr[25][25];

bool tmp[25];

vector<int> ansArr;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int ans = 999;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n / 2; i++)
    {
        tmp[i] = 1;
    }

    do
    {

        vector<int> stTeam;
        vector<int> liTeam;
        int st = 0;
        int link = 0;
        for (int i = 0; i < n; i++)
        {
            if (tmp[i] == 1)
            {
                stTeam.push_back(i);
            }
            else
            {
                liTeam.push_back(i);
            }
        }

        int stN = stTeam.size();
        int liN = liTeam.size();
        for (int i = 0; i < stN; i++)
        {
            for (int j = 0; j < stN; j++)
            {
                int num1 = stTeam[i];
                int num2 = stTeam[j];
                if (i == j)
                    continue;
                st += arr[num1][num2];
            }
        }

        for (int i = 0; i < liN; i++)
        {
            for (int j = 0; j < liN; j++)
            {
                int num1 = liTeam[i];
                int num2 = liTeam[j];
                if (i == j)
                    continue;
                link += arr[num1][num2];
            }
        }

        // cout << st << " " << link << "\n";

        ans = min(ans, abs(link - st));

    } while (prev_permutation(tmp, tmp + n));

    cout << ans;

    // 134 256

    //  13 14 31 34 41 43
}
