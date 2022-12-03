#include <bits/stdc++.h>
using namespace std;
int h, m, s;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> h >> m >> s;

    int curS;
    cin >> curS;

    while (curS--)
    {

        s++;
        if (s == 60)
        {
            s = 0;
            m++;
        }

        if (m == 60)
        {
            m = 0;
            h++;
        }

        if (h == 24)
        {
            h = 0;
        }
    }

    cout << h << " " << m << " " << s;
}
