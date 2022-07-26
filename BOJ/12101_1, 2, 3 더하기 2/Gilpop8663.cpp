#include <bits/stdc++.h>
using namespace std;

int n;
int cnt = 0;
long long k;

vector<int> ans;

vector<string> ansStr;

void func(int sum, vector<int> &ans)
{

    if (sum >= n)
    {
        if (sum == n)
        {
            cnt++;
            if (cnt == k)
            {

                string str;
                for (int i = 0; i < ans.size(); i++)
                {
                    string num = to_string(ans[i]);
                    str += num;
                    str += "+";
                }
                str.pop_back();

                cout << str;
            }
        }
        return;
    }

    for (int i = 1; i <= 3; i++)
    {
        ans.push_back(i);
        func(sum + i, ans);
        ans.pop_back();
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    func(0, ans);

    if (cnt == 0 || cnt < k)
        cout << -1;
}
