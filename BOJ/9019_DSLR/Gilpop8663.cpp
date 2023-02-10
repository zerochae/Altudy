#include <bits/stdc++.h>
using namespace std;

int t, n, m;

bool ch[10005];

int Dfunc(int a)
{
    return a * 2 % 10000;
}
int Sfunc(int a)
{
    if (a == 0)
        return 9999;
    return a - 1;
}

int Lfunc(int a)
{
    return a % 1000 * 10 + a / 1000;
}

int Rfunc(int a)
{

    return a / 10 + a % 10 * 1000;
}

string BFS(int a, int b)
{
    queue<pair<int, string>> q; // 현재 번호, 경로
    fill(ch, ch + 10004, 0);
    ch[a] = 1;
    q.push({a, ""});

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        int num = cur.first;
        string str = cur.second;

        if (num == b)
        {
            return str;
        }

        int dNum = Dfunc(num);
        int sNum = Sfunc(num);
        int lNum = Lfunc(num);
        int rNum = Rfunc(num);

        if (ch[dNum] == 0)
        {
            ch[dNum] = 1;
            q.push({dNum, str + "D"});
        }
        if (ch[sNum] == 0)
        {
            ch[sNum] = 1;
            q.push({sNum, str + "S"});
        }
        if (ch[lNum] == 0)
        {
            ch[lNum] = 1;
            q.push({lNum, str + "L"});
        }
        if (ch[rNum] == 0)
        {
            ch[rNum] = 1;
            q.push({rNum, str + "R"});
        }
    }
    return "";
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n >> m;

        cout << BFS(n, m) << "\n";
        // cout << "시작"
        //      << "\n";
        // cout << Dfunc(n) << "\n";
        // cout << Sfunc(n) << "\n";
        // cout << Lfunc(n) << "\n";
        // cout << Rfunc(n) << "\n";
        // cout << "끝"
        //      << "\n";
    }
}
