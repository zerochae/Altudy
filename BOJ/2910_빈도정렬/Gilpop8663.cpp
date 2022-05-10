#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.X > b.X;
}

vector<pair<int, int>> arr; // { cnt , num}
int main(void)
{
    cin >> n >> m;
    int idx = 0;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        bool chk = false;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i].Y == num)
            {
                chk = true;
                arr[i].X++;
                break;
            }
        }
        if (!chk)
        {
            arr.push_back({1, num});
        }
    }

    // sort(arr.begin(), arr.end(), cmp);
    stable_sort(arr.begin(), arr.end(), cmp);

    for (auto a : arr)
    {
        while (a.X--)
        {
            cout << a.Y << " ";
        }
    }
}
