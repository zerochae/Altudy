#include <bits/stdc++.h>
using namespace std;

int m;

string str;

vector<int> arr[8];

bool ch[15] = {0};

int ans;

void func(int k, int sum)
{
    if (k < str.size() + 1 && k != 0)
    {
        ans = min(ans, k + abs(stoi(str) - sum));
        // cout << sum << "\n";
        // return;
    }
    if (k == str.size() + 1)
    {
        ans = min(ans, k + abs(stoi(str) - sum));
        // cout << sum << "\n";
        return;
    }

    for (int i = 0; i <= 9; i++)
    {
        if (ch[i] == 1)
            continue;
        func(k + 1, sum * 10 + i);
    }

    // for (int i = 0; i < arr[k].size(); i++)
    // {
    //     func(k + 1, sum * 10 + arr[k][i]);
    // }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str >> m;

    ans = abs(stoi(str) - 100);

    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        ch[num] = 1;
    }

    int cnt = 0;

    int pNum = 0;

    for (int i = 0; i < str.size(); i++)
    {
        int minNum = 99999;

        int num = str[i] - '0';

        if (num == 0)
        {
            num = 10;
        }

        for (int j = 0; j <= 9; j++)
        {
            if (ch[j] == 0)
            {

                if (abs(num - j) < minNum)
                {
                    arr[i].clear();
                    arr[i].push_back(j);
                    minNum = abs(num - j);
                }
                else if (abs(num - j) == minNum)
                {
                    arr[i].push_back(j);
                }
            }
        }
    }

    func(0, 0);

    cout << ans;
}
