#include <bits/stdc++.h>
using namespace std;

string str;

int n, m;

int ch[1000001][11];

int func(int k, string sum)
{

    if (k == m)
    {
        return stoi(sum);
    }

    int &result = ch[stoi(sum)][k];

    if (result != -1)
        return result;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (sum[j] == '0' && i == 0)
                continue;
            swap(sum[i], sum[j]);
            result = max(result, func(k + 1, sum));
            swap(sum[i], sum[j]);
        }
    }
    return result;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str >> m;

    n = str.size();

    fill(&ch[0][0], &ch[1000000][11], -1);

    int ans = func(0, str);

    cout << ans;
}
