#include <bits/stdc++.h>
using namespace std;

int n, t;

pair<int, int> home, party;

bool ch[105] = {0};

bool dist(pair<int, int> a, pair<int, int> b)
{
    int tmp = abs(a.first - b.first) + abs(a.second - b.second);
    return tmp <= 1000;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while (t--)
    {
        pair<int, int> arr[105];

        queue<pair<int, int>> q;

        fill(ch, ch + 105, 0);

        cin >> n;

        int num1, num2;

        cin >> num1 >> num2;

        home = {num1, num2};

        for (int i = 0; i < n; i++)
        {
            int dis1, dis2;

            cin >> dis1 >> dis2;

            arr[i] = {dis1, dis2};
        }

        int number, number2;

        cin >> number >> number2;

        party = {number, number2};

        q.push({home.first, home.second});

        bool isFind = 0;

        while (!q.empty())
        {

            pair<int, int> cur = q.front();
            q.pop();

            int x = cur.first;
            int y = cur.second;

            if (dist(cur, party))
            {
                isFind = 1;
                cout << "happy"
                     << "\n";
                break;
            }
            else
            {
                for (int i = 0; i < n; i++)
                {
                    if (ch[i] == 1)
                        continue;

                    if (dist(cur, arr[i]))
                    {
                        ch[i] = 1;
                        q.push({arr[i].first, arr[i].second});
                    }
                }
            }
        }

        if (isFind == 0)
        {
            cout << "sad"
                 << "\n";
        }
    }
}