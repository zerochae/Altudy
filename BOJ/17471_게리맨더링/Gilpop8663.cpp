#include <bits/stdc++.h>
using namespace std;

int n;

int arr[12];

bool connect[12][12] = {0};

bool selc[12] = {0};

bool ch[12] = {0};

int answer = 1e9;

bool checkConnect(vector<int> V, bool T)
{
    fill(ch, ch + 12, 0);

    int num = V[0];
    queue<int> Q;
    Q.push(num);
    ch[num] = 1;
    int cnt = 1;

    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();

        for (int i = 1; i <= n; i++)
        {
            if (connect[i][cur] == 1 && ch[i] == 0 && selc[i] == T)
            {
                ch[i] = 1;
                cnt++;
                Q.push(i);
            }
        }
    }

    if (V.size() == cnt)
    {
        return true;
    }

    return false;
}

bool check()
{
    vector<int> A, B;

    for (int i = 1; i <= n; i++)
    {
        if (selc[i] == 1)
        {
            A.push_back(i);
        }
        else
        {
            B.push_back(i);
        }
    }

    // 1개 이상의 구역은 가지고 있어야 함
    if (A.size() == 0 || B.size() == 0)
        return false;

    bool aState = checkConnect(A, true);
    if (!aState)
    {
        return false;
    }
    bool bState = checkConnect(B, false);
    if (!bState)
    {
        return false;
    }

    return true;
}

void calculate()
{
    int aNum = 0, bNum = 0, diff = 0;
    for (int i = 1; i <= n; i++)
    {
        if (selc[i] == 1)
        {
            aNum += arr[i];
        }
        else
        {
            bNum += arr[i];
        }
    }

    diff = abs(aNum - bNum);
    if (answer > diff)
    {
        answer = diff;
    }
}

void func(int k, int cnt)
{
    // 조합
    if (cnt >= 1)
    {
        if (check())
        {
            calculate();
        }
        // 계산
    }

    for (int i = k; i <= n; i++)
    {
        if (selc[i] == 1)
            continue;
        selc[i] = 1;
        func(i, cnt + 1);
        selc[i] = 0;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++)
    {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            connect[i][x] = 1;
            connect[x][i] = 1;
        }
    }

    func(1, 0);
    if (answer == 1e9)
        answer = -1;
    cout << answer;
}
