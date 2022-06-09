#include <bits/stdc++.h>
using namespace std;

int n;

int arr[] = {1, 5, 10, 50};

bool ch[1005];

set<int> s;

int loop(int a, int d, int sum)
{

    if (a == n)
    {
        if (ch[sum] == 0)
        {
            // cout << sum << "\n";
            ch[sum] = 1;
            s.insert(sum);
        }
        return 0;
    }

    for (int i = d; i < 4; i++)
    {
        loop(a + 1, i, sum + arr[i]);
    }
    return 0;
}

int d[25];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int cnt = 0;
    loop(0, 0, 0);

    cout << s.size();
}
