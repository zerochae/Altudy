#include <bits/stdc++.h>
using namespace std;

int n;

int arr[100005];

int d[30005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    // d[1] = 1; // 1
    // d[2] = 2; // 2 1
    // d[3] = 3; // 3 2 1
    // d[4] = 3; // 4 3 1
    // d[5] = 4; // 5 3 2 1
    // d[6] = //6422

    int maxCnt = 0;
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        int cnt = 2;
        vector<int> numbers;
        n - i;
        int ori = n;              // 100
        int minus = i;            // 62
        numbers.push_back(ori);   // 100
        numbers.push_back(minus); // 1
        while (ori > 0)
        {
            ori -= minus; // 99
            if (ori < 0)
            {
                break;
            }
            numbers.push_back(ori);
            int tmp = ori; // 99
            ori = minus;   // 1
            minus = tmp;   //== 62 - 38
            cnt++;
            // ori = tmp; // 100
        }
        if (cnt > maxCnt)
        {
            maxCnt = cnt;
            ans = numbers;
        }
    }

    cout << maxCnt << "\n";

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}