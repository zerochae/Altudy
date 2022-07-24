#include <bits/stdc++.h>
using namespace std;

int n, m;

vector<int> arr[500005];
bool ch[500005];

int height = 0;

void func(int k, int cnt)
{

    if (arr[k].size() == 1 && k != 1)
    {
        height += cnt;
        return;
    }

    for (int i = 0; i < arr[k].size(); i++)
    {
        if (ch[arr[k][i]] == 1)
            continue;

        ch[arr[k][i]] = 1;
        func(arr[k][i], cnt + 1);
        // ch[arr[k][i]] = 0;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int num1, num2;
        cin >> num1 >> num2;

        arr[num1].push_back(num2);
        arr[num2].push_back(num1);
    }

    ch[1] = 1;
    func(1, 0);

    if (height % 2 == 1)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    // cout << height << "\n";
}
