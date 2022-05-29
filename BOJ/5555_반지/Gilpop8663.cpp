#include <bits/stdc++.h>
using namespace std;

string str;

int n;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;

    cin >> n;

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        string ring;
        cin >> ring;

        ring += ring;

        if (ring.find(str) < 100)
        {
            cnt++;
        }
    }

    cout << cnt;
}
