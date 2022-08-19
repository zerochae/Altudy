#include <bits/stdc++.h>
using namespace std;

int n = 0;

int arr[10010];

void func(int st, int en)
{
    if (st >= en)
    {
        return;
    }

    if (st == en - 1)
    {
        cout << arr[st] << "\n";
        return;
    }
    int idx = st + 1;
    while (idx < en)
    {
        if (arr[st] < arr[idx]) // st 보다 높다면 오른쪽임
        {
            break;
        }
        idx++;
    }

    func(st + 1, idx);
    func(idx, en);
    cout << arr[st] << "\n";
}

int main(void)
{

    int num;
    while (cin >> num)
    {
        arr[n++] = num;
    }

    func(0, n);

    return 0;
}
