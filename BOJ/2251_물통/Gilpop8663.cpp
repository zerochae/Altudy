#include <bits/stdc++.h>
using namespace std;

int A, B, C;

bool ch[201][201][201];

queue<tuple<int, int, int>> q;

vector<int> s;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> B >> C;

    q.push({0, 0, C});

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        int a = get<0>(cur);
        int b = get<1>(cur);
        int c = get<2>(cur);

        if (ch[a][b][c] == 1)
            continue;

        ch[a][b][c] = 1;

        if (a == 0)
            s.push_back(c);

        // A에서 B로 줄 때

        if (a + b > B)
            q.push({a + b - B, B, c});
        else
            q.push({0, a + b, c});

        // A에서 C로 줄 때

        if (a + c > C)
            q.push({a + c - C, b, C});
        else
            q.push({0, b, a + c});

        // B에서 A로 줄 때

        if (a + b > A)
            q.push({A, a + b - A, c});
        else
            q.push({a + b, 0, c});

        // B에서 C로 줄 때

        if (b + c > C)
            q.push({a, b + c - C, C});
        else
            q.push({a, 0, b + c});

        // C에서 A로 줄 때

        if (a + c > A)
            q.push({A, b, a + c - A});
        else
            q.push({a + c, b, 0});

        // C에서 B로 줄 때

        if (b + c > B)
            q.push({a, B, b + c - B});
        else
            q.push({a, b + c, 0});
    }

    sort(s.begin(), s.end());

    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i] << " ";
    }
}
