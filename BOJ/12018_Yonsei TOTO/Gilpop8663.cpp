#include <bits/stdc++.h>
using namespace std;

int t, n, m;
vector<int> qlass;

bool comp(int a, int b)
{
    return a > b;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int p_stu, s_stu;
        vector<int> arr;
        cin >> p_stu >> s_stu;
        for (int j = 0; j < p_stu; j++)
        {
            int num;
            cin >> num;
            arr.push_back(num);
        }

        sort(arr.begin(), arr.end(), comp);

        if (p_stu >= s_stu)
        {
            qlass.push_back(arr[s_stu - 1]);
        }
        else
        {
            qlass.push_back(1);
        }
    }

    sort(qlass.begin(), qlass.end());
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (m - qlass[i] >= 0)
        {
            m -= qlass[i];
            ans++;
        }
        else
        {
            break;
        }
    }

    cout << ans;
}
