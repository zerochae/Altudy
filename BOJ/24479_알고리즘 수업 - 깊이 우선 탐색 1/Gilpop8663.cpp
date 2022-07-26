#include <bits/stdc++.h>
using namespace std;

int n, m, r;

vector<int> arr[100005];

bool ch[100005];

int ans[100005];

deque<int> q;

int cnt = 1;

void func(int k)
{
    ans[k] = cnt++;

    sort(arr[k].begin(), arr[k].end());

    for (int i = 0; i < arr[k].size(); i++)
    {
        int num = arr[k][i];
        if (ch[num] == 1)
            continue;
        ch[num] = 1;
        func(num);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> r;

    for (int i = 0; i < m; i++)
    {
        int num, num2;
        cin >> num >> num2;

        arr[num].push_back(num2);
        arr[num2].push_back(num);
    }

    ch[r] = 1;
    func(r);

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << "\n";
    }
}
