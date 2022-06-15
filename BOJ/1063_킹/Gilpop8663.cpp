#include <bits/stdc++.h>
using namespace std;

string king, stone;

int n;

char board[9][9];

pair<int, int> k;
pair<int, int> s;

char alp[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
string ansK, ansS;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> king >> stone >> n;

    k = {king[0] - 'A' + 1, king[1] - '0'};

    s = {stone[0] - 'A' + 1, stone[1] - '0'};

    // cout << k.first << " " << k.second << "\n";
    // cout << s.first << " " << s.second << "\n";

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;

        string newK, newS, tmp;

        if (str == "B")
        {
            if (k.second == 1)
                continue;
            k.second--;
        }

        if (str == "R")
        {
            if (k.first == 8)
                continue;
            k.first++;
        }

        if (str == "L")
        {
            if (k.first == 1)
                continue;
            k.first--;
        }

        if (str == "T")
        {
            if (k.second == 8)
                continue;
            k.second++;
        }

        if (str == "RT")
        {
            if (k.first == 8 || k.second == 8)
                continue;
            k.first++;
            k.second++;
        }

        if (str == "LT")
        {
            if (k.first == 1 || k.second == 8)
                continue;
            k.first--;
            k.second++;
        }

        if (str == "RB")
        {
            if (k.first == 8 || k.second == 1)
                continue;
            k.first++;
            k.second--;
        }

        if (str == "LB")
        {
            if (k.first == 1 || k.second == 1)
                continue;
            k.first--;
            k.second--;
        }

        if (k.first == s.first && k.second == s.second)
        {
            if (str == "B")
            {
                if (s.second == 1)
                {
                    k.second++;
                    continue;
                }
                s.second--;
            }

            if (str == "R")
            {
                if (s.first == 8)
                {
                    k.first--;
                    continue;
                }
                s.first++;
            }

            if (str == "L")
            {
                if (s.first == 1)
                {
                    k.first++;
                    continue;
                }
                s.first--;
            }

            if (str == "T")
            {
                if (s.second == 8)
                {
                    k.second--;
                    continue;
                }
                s.second++;
            }

            if (str == "RT")
            {
                if (s.first == 8 || s.second == 8)
                {
                    k.first--;
                    k.second--;
                    continue;
                }
                s.first++;
                s.second++;
            }

            if (str == "LT")
            {
                if (s.first == 1 || s.second == 8)
                {
                    k.first++;
                    k.second--;
                    continue;
                }
                s.first--;
                s.second++;
            }

            if (str == "RB")
            {
                if (s.first == 8 || s.second == 1)
                {
                    k.first--;
                    k.second++;
                    continue;
                }
                s.first++;
                s.second--;
            }

            if (str == "LB")
            {
                if (s.first == 1 || s.second == 1)
                {
                    k.first++;
                    k.second++;
                    continue;
                }
                s.first--;
                s.second--;
            }
        }
    }

    for (int i = 1; i <= 8; i++)
    {
        if (k.first == i)
        {
            ansK += alp[i - 1];
        }

        if (s.first == i)
        {
            ansS += alp[i - 1];
        }
    }

    ansK += k.second + '0';

    ansS += s.second + '0';

    cout << ansK << "\n";
    cout << ansS << "\n";
}
