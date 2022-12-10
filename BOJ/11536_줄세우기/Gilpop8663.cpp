#include <bits/stdc++.h>
using namespace std;

int n;

string str;
int answer = -2e9;

int calculate(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        a += b;
        break;
    case '-':
        a -= b;
        break;
    case '*':
        a *= b;
        break;
    }
    return a;
}

void DFS(int idx, int cur)
{
    if (idx >= n)
    {
        answer = max(answer, cur);
        return;
    }

    char op = idx == 0 ? '+' : str[idx - 1];

    if (idx + 2 < n)
    {
        int bracket = calculate(str[idx] - '0', str[idx + 2] - '0', str[idx + 1]);
        DFS(idx + 4, calculate(cur, bracket, op));
    }

    DFS(idx + 2, calculate(cur, str[idx] - '0', op));

    return;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    cin >> str;

    DFS(0, 0);
    cout << answer;
}
