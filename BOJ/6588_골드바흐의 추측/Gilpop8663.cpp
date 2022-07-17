#include <bits/stdc++.h>
using namespace std;

int n;

bool ch[1005000] = {0};
// vector<int> prime;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // fill(ch, ch + 100005, 1);
    ch[0] = 1;
    ch[1] = 1;

    for (int i = 2; i <= 1000000; i++)
    {
        if (ch[i] == 1)
            continue;
        // prime.push_back(i);
        for (int j = i * 2; j <= 1000000; j += i)
        {
            ch[j] = 1;
        }
    }

    // for (int i = 0; i < prime.size(); i++)
    // {
    //     cout << prime[i] << " ";
    // }

    while (true)

    {
        cin >> n;
        if (n == 0)
            break;

        for (int i = 2; i < n; i++)
        {
            if (ch[i] == 1)
                continue;
            if (ch[i] == 0 && ch[n - i] == 0 && n - i > 0)
            {
                int num = n - i;

                cout << n << " = " << i << " + " << num << "\n";
                break;
            }
        }
    }
}
