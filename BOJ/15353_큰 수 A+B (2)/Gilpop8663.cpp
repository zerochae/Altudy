#include <bits/stdc++.h>
using namespace std;

string A, B;

string SUM(string a, string b)
{
    string str;
    vector<int> ans;
    vector<char> arr1;
    vector<char> arr2;

    // 12333  00015
    // 33321 51000

    int bigStr = max(a.size(), b.size());
    int smStr = min(a.size(), b.size());

    int dif = bigStr - smStr;

    // cout << bigStr << " " << smStr << " " << dif << "\n";

    if (a.size() > b.size())
    {
        for (int i = 0; i < dif; i++)
        {
            arr2.push_back('0');
        }
    }
    else if (a.size() < b.size())
    {
        for (int i = 0; i < dif; i++)
        {
            arr1.push_back('0');
        }
    }

    for (int i = 0; i < a.size(); i++)
    {
        arr1.push_back(a[i]);
    }

    for (int i = 0; i < b.size(); i++)
    {
        arr2.push_back(b[i]);
    }

    reverse(arr1.begin(), arr1.end());
    reverse(arr2.begin(), arr2.end());

    for (int i = 0; i < bigStr; i++)
    {
        int num1 = arr1[i] - '0';
        int num2 = arr2[i] - '0';

        // cout << num1 << " " << num2 << "\n";

        ans.push_back(num1 + num2);
    }

    for (int i = 0; i < ans.size() - 1; i++)
    {
        ans[i + 1] = ans[i + 1] + ans[i] / 10;
        str += (ans[i] % 10) + '0';
    }

    if (ans[ans.size() - 1] >= 10)
    {
        str += (ans[ans.size() - 1] % 10) + '0';
        str += 1 + '0';
    }
    else
    {
        str += (ans[ans.size() - 1] % 10) + '0';
    }

    reverse(str.begin(), str.end());

    return str;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> B;

    // cout << A << " " << B << "\n";

    string ans;

    ans = SUM(A, B);

    cout << ans;
}
