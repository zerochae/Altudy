#include <bits/stdc++.h>
using namespace std;

int n, h;

vector<int> bot;
vector<int> top;

int ans = 200001, ansCnt = 0;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> h;

    for (int i = 0; i < n / 2; i++)
    {
        int a, b;
        cin >> a >> b;
        bot.push_back(a);
        top.push_back(b);
    }

    sort(bot.begin(), bot.end());
    sort(top.begin(), top.end());

    for (int i = 1; i <= h; i++)
    {
        int botIdx = lower_bound(bot.begin(), bot.end(), i) - bot.begin();
        int topIdx = upper_bound(top.begin(), top.end(), h - i) - top.begin();

        int result = n - (botIdx + topIdx);

        if (ans == result)
        {
            ansCnt++;
        }
        else if (ans > result)
        {
            ans = result;
            ansCnt = 1;
        }
    }

    cout << ans << " " << ansCnt;
}
