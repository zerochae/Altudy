#include <bits/stdc++.h>
using namespace std;

int n, m;

const int INF = 1e9;

tuple<int, int, int, int> arr[100005];

pair<int, int> find(int m, int d)
{
    int maxM = 0, maxD = 0;

    for (int i = 0; i < n; i++)
    {
        int stM = get<0>(arr[i]);
        int stD = get<1>(arr[i]);
        int enM = get<2>(arr[i]);
        int enD = get<3>(arr[i]);

        if (stM > m)
            continue;
        if (stM == m && stD > d)
            continue;

        if (maxM < enM)
        {
            maxM = enM;
            maxD = enD;
        }
        else if (maxM == enM && maxD < enD)
        {
            maxD = enD;
        }
    }

    return {maxM, maxD};
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int stM, stD, enM, enD;
        cin >> stM >> stD >> enM >> enD;
        arr[i] = {stM, stD, enM, enD};
    }

    int cnt = 0;
    int curM = 3, curD = 1;

    int ans = 0;

    while (true)
    {
        if (curM == 12 || cnt > n)
        {
            break;
        }
        auto cur = find(curM, curD);
        curM = cur.first;
        curD = cur.second;
        cnt += 1;
        ans += 1;
        // cout << cur.first << " " << cur.second << "\n";
    }

    if (curM < 12)
    {
        ans = 0;
    }

    cout << ans;
}
