#include <bits/stdc++.h>
using namespace std;

int n;

string arr[15];

vector<int> ch;

set<char> s;

int sumArr[30];

vector<char> strArr;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        int num = 1;
        for (int j = arr[i].size() - 1; j >= 0; j--)
        {
            char str = arr[i][j];
            s.insert(str);
            sumArr[str - 'A'] += num;
            num *= 10;
        }
    }

    int ans = 0;
    int mulNum = 9;

    sort(sumArr, sumArr + 30, greater<int>());

    for (int i = 0; i < s.size(); i++)
    {
        ans += sumArr[i] * mulNum--;
    }
    cout << ans;
}
