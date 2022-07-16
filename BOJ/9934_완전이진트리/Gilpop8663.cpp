#include <bits/stdc++.h>
using namespace std;

int k;

bool ch[1030] = {0};
vector<int> arr;

vector<int> s[11];

void func(int st, int en, int depth)
{

    if (st == en)
    {
        s[depth].push_back(arr[st]);
        return;
    }

    int mid = (st + en) / 2;

    s[depth].push_back(arr[mid]);

    func(st, mid - 1, depth + 1);
    func(mid + 1, en, depth + 1);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k;

    for (int i = 0; i < pow(2, k) - 1; i++)
    {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    func(0, arr.size() - 1, 0);

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < s[i].size(); j++)
        {
            cout << s[i][j] << " ";
        }

        cout << "\n";
    }
}
