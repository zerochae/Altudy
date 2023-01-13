#include <bits/stdc++.h>
using namespace std;

int n, m;

int getLength(int num)
{
    int length = 0;

    for (int start = 1, len = 1; start <= num; start *= 10, len += 1)
    {
        int end = start * 10 - 1;
        if (end > num)
        {
            end = num;
        }

        length += ((end - start) + 1) * len;
    }

    return length;
}

void go(int start, int end)
{
    int pos;

    while (start <= end)
    {
        int mid = (start + end) / 2;
        int length = getLength(mid);

        if (length < m) // 오른쪽
        {
            start = mid + 1;
        }
        else // 왼쪽
        {
            pos = mid;
            end = mid - 1;
        }
    }

    int c = getLength(pos);

    string str = to_string(pos);

    cout << str[str.size() - 1 - (c - m)];
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    // cout << getLength(n);

    if (getLength(n) < m)
    {
        cout << -1;
        return 0;
    }

    go(0, n);
}
