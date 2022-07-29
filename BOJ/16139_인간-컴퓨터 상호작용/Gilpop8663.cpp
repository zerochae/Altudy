#include <bits/stdc++.h>
#include <cstring>

using namespace std;

string str;

int n;

char s2[2];
int s1[500005][28] = {0};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> str;

    cin >> n;

    for (int i = 0; i < str.size(); i++)
    {
        int num = str[i] - '0' - 48;

        for (int j = 0; j <= 26; j++)
        {
            s1[i][j] = s1[i - 1][j];
        }

        s1[i][num] = s1[i - 1][num] + 1;
    }

    for (int i = 0; i < n; i++)
    {
        char s4;
        int st, en;
        cin >> s4 >> st >> en;
        int num = s4 - '0' - 48;

        int cnt = 0;

        // cout << s1[st - 1][num] << " " << s1[en][num] << "\n";

        int ans = s1[en][num] - s1[st - 1][num];
        cout << ans << "\n";
    }
}
