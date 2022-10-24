#include <bits/stdc++.h>
using namespace std;

int n;

int arr[1000005];

stack<pair<int, int>> s;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        // cout << s.top().first << " " << s.top().second << " " << num << "\n";
        if (i == 0)
        {
            s.push({i, num});
        }
        else
        {

            while (!s.empty())
            {
                if (num <= s.top().second)
                    break;
                arr[s.top().first] = num;
                s.pop();
            }

            s.push({i, num});
        }
    }

    while (!s.empty())
    {
        arr[s.top().first] = -1;
        s.pop();
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
