#include <bits/stdc++.h>
using namespace std;

int n, m;

vector<int> arr[2005];

bool ch[2005];

queue<pair<int, int>> q;

bool ans = 0;

void func(int num, int cnt)
{
    // cout << num << " " << cnt << "\n";
    if (cnt == 4)
    {
        ans = 1;
        return;
    }

    int len = arr[num].size();

    for (int i = 0; i < len; i++)
    {
        int number = arr[num][i];
        if (ch[number] == 1)
            continue;
        ch[number] = 1;
        func(number, cnt + 1);
        ch[number] = 0;
    }

    return;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int num, num2;
        cin >> num >> num2;
        arr[num].push_back(num2);
        arr[num2].push_back(num);
    }

    for (int i = 0; i < n; i++)
    {
        ch[i] = 1;
        func(i, 0);
        ch[i] = 0;
        if (ans == 1)
        {
            cout << ans;
            return 0;
        }
    }
    cout << ans;
    return 0;
}
