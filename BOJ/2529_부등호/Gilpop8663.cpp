#include <bits/stdc++.h>
using namespace std;

int n;

char arr[10];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    string maxAns;
    string minAns;

    long long maxNum = 0;
    long long minNum = 99999999999;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i <= 9; i++)
    {
        queue<tuple<int, int, string>> q;
        string str;

        q.push({i, 0, str});

        while (!q.empty())
        {

            bool ch[10] = {0};
            tuple<int, int, string> cur = q.front();
            q.pop();

            int num = get<0>(cur);
            int y = get<1>(cur);

            string str = get<2>(cur);
            str += num + '0';

            for (int i = 0; i < str.size(); i++)
            {
                ch[str[i] - '0'] = 1;
            }

            // cout << num << " " << y << " " << str << "\n";
            if (y == n)
            {
                // cout << str << "\n";
                long long number = stoll(str);
                // cout << number << "\n";

                if (maxNum < number)
                {
                    maxAns = str;
                    maxNum = number;
                }

                if (minNum > number)
                {
                    minAns = str;
                    minNum = number;
                }
                continue;
            }

            if (arr[y] == '<')
            {
                for (int i = 0; i <= 9; i++)
                {
                    if (ch[i] == 1)
                        continue;
                    if (num > i)
                        continue;
                    q.push({i, y + 1, str});
                }
            }

            if (arr[y] == '>')
            {

                for (int i = 0; i <= 9; i++)
                {
                    if (ch[i] == 1)
                        continue;
                    if (num < i)
                        continue;
                    q.push({i, y + 1, str});
                }
            }
        }
    }

    cout << maxAns << "\n";
    cout << minAns;
}
