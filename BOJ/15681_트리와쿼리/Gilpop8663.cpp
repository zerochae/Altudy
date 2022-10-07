#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, r, Q;

vector<int> arr[100005];

bool ch[100005] = {0};

int ans[100005];

int func(int k)
{
    int result = ans[k];
    if (result != 0)
    {
        return ans[k];
    }

    int len = arr[k].size();

    result = 1;

    for (int i = 0; i < len; i++)
    {
        int num = arr[k][i];
        if (ch[num] == 1)
            continue;
        ch[num] = 1;
        result += func(num);
    }

    ans[k] = result;

    return result;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> r >> Q;

    for (int i = 0; i < n - 1; i++)
    {
        int num1, num2;
        cin >> num1 >> num2;

        arr[num1].push_back(num2);
        arr[num2].push_back(num1);
    }
    ch[r] = 1;
    func(r);
    for (int i = 0; i < Q; i++)
    {
        int num;
        cin >> num;
        cout << ans[num] << "\n";
    }
}
