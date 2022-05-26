#include <bits/stdc++.h>
using namespace std;

string n;

char arr[1005];

vector<string> ans;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int num = n.size();

    for (int i = 0; i < num; i++)
    {
        arr[i] = n[i];
    }

    for (int i = 0; i < num - 2; i++)
    {
        for (int j = i + 1; j < num - 1; j++)
        {
            if (i >= j)
                continue;
            char arr2[1005];
            string str;
            copy(arr, arr + num, arr2);
            reverse(arr2, arr2 + i + 1);
            reverse(arr2 + i + 1, arr2 + j + 1);
            reverse(arr2 + j + 1, arr2 + num);

            for (int m = 0; m < num; m++)
            {
                str += arr2[m];
            }
            // cout << str << "\n";
            ans.push_back(str);
            // cout << "시작"
            //      << "\n";
            // cout << 0 << " " << j << "\n";
            // cout << j << " " << i << "\n";
            // cout << i << " " << num << "\n";
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans[0];
}