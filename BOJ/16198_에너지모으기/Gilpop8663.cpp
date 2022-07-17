#include <bits/stdc++.h>

using namespace std;

int n;

int arr[15];

vector<int> s;

int ans = 0;

void func(vector<int> s1, int sum)
{

    int len = s1.size();
    if (len == 2)
    {
        // cout << sum << "\n";
        ans = max(ans, sum);
        return;
    }

    for (int i = 1; i < len - 1; i++)
    {
        int v = s1[i];
        int num = s1[i - 1] * s1[i + 1];

        s1.erase(s1.begin() + i);
        func(s1, sum + num);
        s1.insert(s1.begin() + i, v);
    }
    return;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        s.push_back(num);
    }

    func(s, 0);

    cout << ans;
}
