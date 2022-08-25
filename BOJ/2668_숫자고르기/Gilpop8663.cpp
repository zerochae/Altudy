#include <bits/stdc++.h>
using namespace std;

int n;

int arr[105];
int ch[105];
set<int> s;

void func(int st, int cur)

{

    if (ch[cur] == 0)
    {
        ch[cur] = st;
        func(st, arr[cur]);
    }
    else if (cur == st)
    {
        s.insert(st);
        return;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++)
    {
        fill(ch, ch + 105, 0);
        func(i, i);
    }

    cout << s.size() << "\n";

    for (auto num : s)
    {
        cout << num << "\n";
    }
}