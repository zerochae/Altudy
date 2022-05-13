#include <bits/stdc++.h>
using namespace std;

int n;
string str1;
string str2;

string a[1005];
string b[1005];
int d[1005][1005];

/*
풀이 방법
1. 끝 자리를 비교해서 같은 글자가 있는지 체크한다.
2. dp 테이블을 만들어 점화식을 이용해 푼다.
*/

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str1 >> str2;

    vector<string> ans;

    for (int i = 1; i <= str1.size(); i++)
    {
        a[i] = str1[i - 1];
    }
    for (int i = 1; i <= str2.size(); i++)
    {
        b[i] = str2[i - 1];
    }

    for (int i = 1; i <= str1.size(); i++)
    {
        for (int j = 1; j <= str2.size(); j++)
        {
            if (a[i] == b[j]) // 끝자리가 같을 경우 +1 임.
            {
                d[i][j] = d[i - 1][j - 1] + 1;
            }
            else
            {
                d[i][j] = max(d[i - 1][j], d[i][j - 1]);
            }
            // cout << d[i][j] << "\n";
        }
    }

    cout << d[str1.size()][str2.size()] << "\n";

    // 어떤 문장이 LCS 인지 구하는 로직

    /*
    int idx1 = str1.size();
    int idx2 = str2.size();
    while (d[idx1][idx2] != 0)
    {

        if (a[idx1] == b[idx2])
        {
            ans.push_back(a[idx1]);
            idx1--;
            idx2--;
        }
        else
        {
            if (d[idx1 - 1][idx2] > d[idx1][idx2 - 1])
            {
                idx1--;
            }
            else
            {
                idx2--;
            }
        }
    }

    reverse(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    */
}
