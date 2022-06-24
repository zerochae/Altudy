#include <bits/stdc++.h>
using namespace std;

int n, m;

vector<pair<int, int>> q;

int arr[1005];
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int minimum = 0;

    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }

    // cout << q.size();

    for (int i = 0; i < m; i++)
    {

        // cout << i << " " << q.size() << " " << arr[i] << "\n";
        bool isFind = 0;
        for (int j = 0; j < q.size(); j++)
        {
            pair<int, int> cur = q[j];

            // cout << cur.first << " " << cur.second << "\n";
            if (cur.first == arr[i])
            {
                q[j] = {cur.first, cur.second + 1};
                isFind = 1;
            }
        }

        if (q.size() < n)
        {
            if (isFind == 0)
            {
                q.push_back({arr[i], 1});
            }
        }
        else
        {

            if (isFind == 0)
            {

                int minIdx = 0;
                int minNum = 99999;
                for (int j = 0; j < n; j++)
                {
                    pair<int, int> cur = q[j];

                    if (cur.second < minNum)
                    {
                        minNum = cur.second;
                        minIdx = j;
                    }
                }

                minimum = minIdx;
                for (int j = minimum; j < q.size(); j++)
                {

                    if (q.size() - 1 == j)
                    {
                        q[j] = {arr[i], 1};
                    }
                    else
                    {

                        q[j] = q[j + 1];
                    }
                }
            }
        }
    }

    sort(q.begin(), q.end());

    for (int i = 0; i < q.size(); i++)
    {
        pair<int, int> cur = q[i];

        cout << cur.first << " ";
    }

    // cout << q.size();
}
