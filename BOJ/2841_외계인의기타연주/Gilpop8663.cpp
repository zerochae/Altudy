#include <bits/stdc++.h>
using namespace std;

int n, m;

int j;

vector<int> arr[500000];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int num, num2;
        cin >> num >> num2;

        bool isFind = 0;

        for (int j = arr[num].size() - 1; j >= 0; j--)
        {
            if (arr[num][j] < num2)
            {
                isFind = 1;
                arr[num].push_back(num2);
                ans++;
                break;
            }
            else if (arr[num][j] == num2)
            {
                isFind = 1;
                break;
            }
            else
            {
                arr[num].pop_back();
                ans++;
            }
        }

        if (isFind == 0)
        {
            ans++;
            arr[num].push_back(num2);
        }
    }

    cout << ans;
}